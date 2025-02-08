#include <iostream>
#include "iter.hpp"

template <typename T>
void print(const T& element)
{
    std::cout << element << " ";
}

template <typename T>
void square(T& element)
{
    element *= element;
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Before: ";
    iter(intArray, intArraySize, print<int>);
    std::cout << std::endl;

    std::cout << "After: ";
    iter(intArray, intArraySize, square<int>);
    iter(intArray, intArraySize, print<int>);
    std::cout << std::endl;

    double doubleArray[] = {1.1, 2.2, 3.3};
    size_t doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Before: ";
    iter(doubleArray, doubleArraySize, print<double>);
    std::cout << std::endl;

    std::cout << "After: ";
    iter(doubleArray, doubleArraySize, square<double>);
    iter(doubleArray, doubleArraySize, print<double>);
    std::cout << std::endl;

    std::string stringArray[] = {"Du", "es", "im", "srti", "tiqyan"};
    size_t stringArraySize = sizeof(stringArray) / sizeof(stringArray[0]);

    std::cout << "String Array: ";
    iter(stringArray, stringArraySize, print<std::string>);
    std::cout << std::endl;

    return 0;
}