#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iterator>
#include <typeinfo>
#include <iostream>
#include <sstream>
#include <ctime>
#include <deque>
#include <list>
#include <vector>
#include <cmath>

/* Compute Jacobsthal numbers for optimized merging order */
int Jacobsthal(int index);

/* Implement std::next equivalent for std::list as list does not have operator+ */
template<typename T>
T next(T it, typename std::iterator_traits<T>::difference_type n = 1)
{
    std::advance(it, n);
    return it;
}

/* Implement std::next equivalent for std::list as list does not have operator- */
template<typename T>
T prev(T it, typename std::iterator_traits<T>::difference_type n = -1)
{
    std::advance(it, n);
    return it;
}

/* Functor to extract integer from a string */
struct stringToInt
{
    int operator()(const std::string& str) const
    {
        std::stringstream ss(str);
        int num;
        if (!(ss >> num)) {
            throw std::invalid_argument("Error: Invalid string to int conversion.");
        }
        return num;
    }
};

/* Merge-Insertion Sort */
namespace PmergeMe
{

// 📌 Insert elements from 'pending' into 'sortedMain' using Jacobsthal sequence
template <typename Container>
void insertElements(Container& sortedMain, Container& pending, typename Container::value_type leftoverElement, 
                    Container& remainingElements, Container& originalContainer, bool hasLeftover, int order) 
{
    typename Container::iterator insertPosition;

    // If only one element is pending, insert it directly in the correct position
    if (pending.size() == 1) 
    {
        insertPosition = std::upper_bound(sortedMain.begin(), sortedMain.end(), *pending.begin());
        sortedMain.insert(insertPosition, *pending.begin());
    } 
    else if (!pending.empty()) 
    {   // If there are multiple elements, insert them using Jacobsthal ordering
        size_t jacobIndex = 3;  // Start with Jacobsthal(3)
        size_t insertedCount = 0;
        size_t elementsToInsert;
        size_t shift;

        while (!pending.empty()) {
            elementsToInsert = Jacobsthal(jacobIndex) - Jacobsthal(jacobIndex - 1);
            if (elementsToInsert > pending.size())
                elementsToInsert = pending.size();
            shift = 0;

            while (elementsToInsert) {
                insertPosition = sortedMain.begin();

                if (Jacobsthal(jacobIndex + insertedCount) - shift <= sortedMain.size()) {
                    std::advance(insertPosition, Jacobsthal(jacobIndex + insertedCount) - shift);
                } else {
                    insertPosition = sortedMain.end();
                }

                insertPosition = std::upper_bound(sortedMain.begin(), insertPosition, *::next(pending.begin(), elementsToInsert - 1));
                sortedMain.insert(insertPosition, *::next(pending.begin(), elementsToInsert - 1));
                pending.erase(::next(pending.begin(), elementsToInsert - 1));

                elementsToInsert--;
                shift++;
                insertedCount++;
            }
            jacobIndex++;
        }
    }

    // 📌 Rebuild sorted container with the correct order
    Container updatedSortedContainer;

    // If an extra (odd) element exists, insert it in the correct position
    if (hasLeftover) {
        insertPosition = std::upper_bound(sortedMain.begin(), sortedMain.end(), leftoverElement);
        sortedMain.insert(insertPosition, leftoverElement);
    }

    // 📌 Reconstruct the sorted sequence in the correct order
    for (typename Container::iterator it = sortedMain.begin(); it != sortedMain.end(); ++it) {
        typename Container::iterator foundPos = std::find(originalContainer.begin(), originalContainer.end(), *it);
        typename Container::iterator insertStart = foundPos;
        std::advance(insertStart, -(order - 1));
        updatedSortedContainer.insert(updatedSortedContainer.end(), insertStart, ::next(foundPos));
    }

    updatedSortedContainer.insert(updatedSortedContainer.end(), remainingElements.begin(), remainingElements.end());
    originalContainer = updatedSortedContainer;
}

// 📌 Recursive function for Merge-Insertion Sort
template <typename Container>
void sort(Container &container) {
    static int order = 1;  // Initial order value

    int groupSize = container.size() / order;
    if (groupSize < 2)
        return;

    bool hasLeftover = groupSize % 2 == 1;
    typename Container::iterator segmentStart = container.begin();
    typename Container::iterator segmentEnd = segmentStart;
    std::advance(segmentEnd, (order * groupSize) - (hasLeftover * order));

    // 📌 Pairwise comparisons and swaps
    for (typename Container::iterator it = segmentStart; it != segmentEnd; std::advance(it, order * 2)) {
        if (*::next(it, order - 1) > *::next(it, order * 2 - 1)) {
            for (int i = 0; i < order; i++) {
                std::iter_swap(::next(it, i), ::next(it, i + order));
            }
        }
    }

    // 📌 Recursive sorting of sub-groups
    order *= 2;
    sort(container);
    order /= 2;

    // 📌 Separate main and pending elements
    Container sortedMain;
    Container pendingElements;
    typename Container::value_type leftoverElement = 0;
    Container remainingElements;

    // Extract first sorted pairs
    sortedMain.push_back(*::next(segmentStart, order - 1));
    sortedMain.push_back(*::next(segmentStart, order * 2 - 1));

    for (typename Container::iterator it = ::next(segmentStart, order * 2); it != segmentEnd; std::advance(it, order)) {
        pendingElements.push_back(*::next(it, order - 1));
        std::advance(it, order);
        sortedMain.push_back(*::next(it, order - 1));
    }

    if (hasLeftover)
        leftoverElement = *::next(segmentEnd, order - 1);

    remainingElements.insert(remainingElements.end(), ::next(segmentEnd, order * hasLeftover), container.end());

    // 📌 Insert pending elements and leftover elements back in sorted order
    if (hasLeftover || !pendingElements.empty()) {
        insertElements(sortedMain, pendingElements, leftoverElement, remainingElements, container, hasLeftover, order);
    }

}

/* Determine container type */
template <typename Container>
std::string getContainerType() 
{
    if (typeid(Container) == typeid(std::vector<typename Container::value_type>)) {
        return "std::vector";
    }
    else if (typeid(Container) == typeid(std::deque<typename Container::value_type>)) {
        return "std::deque";
    }
    else if (typeid(Container) == typeid(std::list<typename Container::value_type>)) {
        return "std::list";
    }
    return "Unknown container";
}






} // namespace PmergeMe



/* Print Container Sequence */
template <typename Container>
void printSequence(const std::string& message, const Container& container) 
{
    std::cout << message;
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) 
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

/* Benchmark Merge-Insertion Sort */
template <typename Container>
void benchmarkMergeInsertionSort(Container& container, bool printInfo = true)
{
    std::clock_t startClock = std::clock();
    PmergeMe::sort(container);
    std::clock_t endClock = std::clock();

    if (printInfo)
    {
        double duration = 1000.0 * (endClock - startClock) / CLOCKS_PER_SEC;
        std::cout << "Time to process a range of " << container.size() << " elements with " 
                  << PmergeMe::getContainerType<Container>() << " : " << duration << " ms" 
                  << std::endl;
    }
}

#endif // PMERGEME_HPP
