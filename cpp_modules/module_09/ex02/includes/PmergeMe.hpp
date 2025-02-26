#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iterator>
#include <typeinfo>
#include <iostream>
#include <sstream>
#include <ctime>

template<typename T>
T   next(T it, typename std::iterator_traits<T>::difference_type n = 1)
{
    std::advance(it, n);
    return it;
}

template<typename T>
T   prev(T it, typename std::iterator_traits<T>::difference_type n = -1)
{
    std::advance(it, n);
    return it;
}

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



namespace PmergeMe
{

template<typename ForwardIt, typename T>
void insertIntoSortedRange(ForwardIt begin, ForwardIt end, const T& value)
{
    ForwardIt it = std::lower_bound(begin, end, value);
    if (it != end) {
        std::copy_backward(it, end, next(end));
    }
    *it = value;
}

template <typename ForwardIterator1, typename ForwardIterator2, typename OutputIterator>
void mergeSortedRanges(ForwardIterator1 begin1, ForwardIterator1 end1, ForwardIterator2 begin2, ForwardIterator2 end2, OutputIterator out) {
    while (begin1 != end1 && begin2 != end2) 
    {
        if (*begin1 < *begin2) {
            *out++ = *begin1++;
        } else {
            *out++ = *begin2++;
        }
    }
    while (begin1 != end1) 
    {
        *out++ = *begin1++;
    }
    while (begin2 != end2) 
    {
        *out++ = *begin2++;
    }
}

template<typename ForwardIt>
void    mergeInsertionSort(ForwardIt begin, ForwardIt end)
{
    typename std::iterator_traits<ForwardIt>::iterator_category type;
    size_t size = std::distance(begin, end);
    if (size <= 1) {
        return;
    }

    ForwardIt mid = begin;
    std::advance(mid, size / 2);

    for (ForwardIt it = begin; it != mid; ++it)
    {
        ForwardIt midIt = it;
        std::advance(midIt, size / 2);
        if (*it > *midIt) {
            std::iter_swap(it, midIt);
        }
    }

    ForwardIt largerStart = begin;
    std::advance(largerStart, size / 2);
    mergeInsertionSort(largerStart, end);

    ForwardIt sortedEnd = begin;
    std::advance(sortedEnd, size / 2);
    if (size % 2 != 0) {
       ++sortedEnd;
    }

    for (ForwardIt it = begin; it != mid; ++it)
    {
        insertIntoSortedRange(begin, sortedEnd, *it);
    }

    mergeSortedRanges(begin, sortedEnd, largerStart, end, begin);
}

} // namespace PmergeMe

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

template <typename ForwardIt>
void benchmarkMergeInsertionSort(ForwardIt begin, ForwardIt end, const std::string& contName)
{
    std::clock_t startClock = std::clock();
    PmergeMe::mergeInsertionSort(begin, end);
    std::clock_t endClock = std::clock();

    double duration = 1000.0 * (endClock - startClock) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << std::distance(begin, end) << " elements with " << contName << " : " << duration << " ms" << std::endl;
}

#endif // PMERGEME_HPP