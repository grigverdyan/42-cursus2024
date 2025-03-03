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

#define RESET    "\033[0m"
#define RED      "\033[31m"
#define GREEN    "\033[32m"
#define BLUE     "\033[34m"

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
T prev(T it, typename std::iterator_traits<T>::difference_type n = 1)
{
    std::advance(it, -n);
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

/* Namespace for Merge-Insertion Sort */
namespace PmergeMe
{

/* Rebuild the sorted container with the correct order using Jacobsthal sequence for optimized merging order */
template <typename Container>
void insertElements(Container& sortedMain, Container& pending, typename Container::value_type leftoverElement, 
                    Container& remainingElements, Container& originalContainer, bool hasLeftover, int order) 
{
    typedef typename Container::iterator iterator;

    iterator insertPosition;

    // If only one element is pending, insert it directly into the correct position
    if (pending.size() == 1) 
    {
        insertPosition = std::upper_bound(sortedMain.begin(), sortedMain.end(), *pending.begin());
        sortedMain.insert(insertPosition, *pending.begin());
    } 
    else if (pending.size() > 1) 
    {   // If there are multiple elements, insert them using Jacobsthal ordering

        size_t jacobIndex = 3;  // Start with Jacobsthal(3)
        size_t insertedCount = 0;
        size_t elementsToInsert;
        size_t shift;

        while (!pending.empty()) 
        {
            elementsToInsert = Jacobsthal(jacobIndex) - Jacobsthal(jacobIndex - 1);
            if (elementsToInsert > pending.size()) {
                elementsToInsert = pending.size();
            }
            shift = 0;

            while (elementsToInsert) 
            {
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

    // Rebuild sorted container with the correct order
    Container updatedSortedContainer;

    // If an extra (odd) element exists, insert it in the correct position
    if (hasLeftover) 
    {
        insertPosition = std::upper_bound(sortedMain.begin(), sortedMain.end(), leftoverElement);
        sortedMain.insert(insertPosition, leftoverElement);
    }

    // Reconstruct the sorted sequence in the correct order
    for (iterator it = sortedMain.begin(); it != sortedMain.end(); ++it) 
    {
        iterator foundPos = std::find(originalContainer.begin(), originalContainer.end(), *it);
        if (foundPos == originalContainer.end()) {
            continue;
        }
        //updatedSortedContainer.insert(updatedSortedContainer.end(), ::prev(foundPos, order - 1), ::next(foundPos, 1));
        
        // iterator insertStart = foundPos;
        // std::advance(insertStart, -(order - 1));
        // updatedSortedContainer.insert(updatedSortedContainer.end(), insertStart, ::next(foundPos));
        
        iterator insertStart = foundPos;
        if (std::distance(originalContainer.begin(), foundPos) >= order - 1) {
            std::advance(insertStart, -(order - 1));
        } else {
            insertStart = originalContainer.begin(); // Prevent invalid backward traversal
        }
        iterator insertEnd = foundPos;
        std::advance(insertEnd, 1); // Move one step forward (safe way to create a range)
    
        // Ensure insertEnd is never beyond `originalContainer.end()`
        if (insertEnd == originalContainer.end()) {
            insertEnd = originalContainer.end();
        }
    
        // Validate range before inserting
        if (insertStart != insertEnd) {
           updatedSortedContainer.insert(updatedSortedContainer.end(), insertStart, insertEnd);
        }
    }

    updatedSortedContainer.insert(updatedSortedContainer.end(), remainingElements.begin(), remainingElements.end());
    originalContainer = updatedSortedContainer;
}

/* Recursive function for Merge-Insertion Sort */
template <typename Container>
void sort(Container &container) 
{
    typedef typename Container::value_type value_type;
    typedef typename Container::iterator iterator;

    static int order = 1;  // Initial order value

    int groupSize = container.size() / order;
    if (groupSize < 2) {
        return;
    }

    bool hasLeftover = groupSize % 2 == 1;
    typename Container::iterator segmentStart = container.begin();
    typename Container::iterator segmentEnd = segmentStart;
    std::advance(segmentEnd, (order * groupSize) - (hasLeftover * order));

    // Swap elements in pairs if they are in the wrong order
    for (iterator it = segmentStart; it != segmentEnd; std::advance(it, order * 2)) 
    {
        if (*::next(it, order - 1) > *::next(it, order * 2 - 1)) 
        {
            for (int i = 0; i < order; ++i) 
            {
                std::iter_swap(::next(it, i), ::next(it, i + order));
            }
        }
    }

    // Double the order and sort the container sub-groups
    order *= 2;
    sort(container);
    order /= 2;

    // Separate main and pending elements
    Container sortedMain;
    Container pendingElements;
    value_type leftoverElement = 0;
    Container remainingElements;

    // Extract first sorted pairs
    sortedMain.push_back(*::next(segmentStart, order - 1));
    sortedMain.push_back(*::next(segmentStart, order * 2 - 1));

    for (iterator it = ::next(segmentStart, order * 2); it != segmentEnd; std::advance(it, order)) 
    {
        pendingElements.push_back(*::next(it, order - 1));
        std::advance(it, order);
        sortedMain.push_back(*::next(it, order - 1));
    }

    if (hasLeftover) {
        leftoverElement = *::next(segmentEnd, order - 1);
    }
    remainingElements.insert(remainingElements.end(), ::next(segmentEnd, order * hasLeftover), container.end());

    // Insert pending elements and leftover elements back in sorted order
    if (hasLeftover || !pendingElements.empty()) {
        insertElements(sortedMain, pendingElements, leftoverElement, remainingElements, container, hasLeftover, order);
    }
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
        std::cout << BLUE << "Time to process a range of " << container.size() << " elements with " 
                  << getContainerType<Container>() << " : " <<GREEN << duration << " ms" 
                  << RESET << std::endl;
    }
}

#endif // PMERGEME_HPP
