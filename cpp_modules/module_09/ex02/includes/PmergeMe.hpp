#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iterator>
#include <iostream>
#include <stdexcept>

void runSortingAlgorithm(int argc, char* argv[]);

template <typename T>
void merge(typename T::iterator left, typename T::iterator mid, typename T::iterator right)
{
    typename T::iterator leftStart = left, rightStart = mid + 1;
    std::vector<typename T::value_type> temp;

    while (leftStart <= mid && rightStart <= right)
	{
        if (*leftStart <= *rightStart) 
        {
            temp.push_back(*leftStart);
            ++leftStart;
        } else 
        {
            temp.push_back(*rightStart);
            ++rightStart;
        }
    }

    while (leftStart <= mid) 
    {
        temp.push_back(*leftStart);
        ++leftStart;
    }

    while (rightStart <= right) 
    {
        temp.push_back(*rightStart);
        ++rightStart;
    }

    for (size_t i = 0; i < temp.size(); ++i) 
    {
        *left = temp[i];
        ++left;
    }
}

template <typename T>
void mergeSort(T& container, typename T::iterator left, typename T::iterator right)
{
    if (left < right) 
    {
        typename T::iterator mid = left + (right - left) / 2;
        mergeSort(container, left, mid);
        mergeSort(container, mid + 1, right);
        merge<T>(left, mid, right);
    }
}

template <typename T>
void insertionSort(T& container)
{
    typename T::iterator it = container.begin();

    ++it;
    for (; it != container.end(); ++it)
	{
        typename T::value_type key = *it;
        typename T::iterator j = it;

        while (j != container.begin() && *(j - 1) > key)
		{
            *j = *(j - 1);
            --j;
        }
        *j = key;
    }
}

template <typename T>
void mergeInsertionSort(T& container)
{
    size_t size = container.size();

    if (size <= 10) 
    {
        insertionSort(container);
    } else 
    {
        mergeSort(container, container.begin(), container.end() - 1);
    }
}

#endif // PMERGEME_HPP