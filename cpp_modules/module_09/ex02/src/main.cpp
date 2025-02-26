#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <list>

std::vector<int> getArguments(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    try 
    {
        if (argc <= 2) {
            throw std::invalid_argument("Usage: ./PmergeMe \"Range of positive integers\"");
        }
        std::vector<int> inputVec = getArguments(argc, argv);

        std::deque<int> inputDeque(inputVec.begin(), inputVec.end());
        std::list<int> inputList(inputVec.begin(), inputVec.end());

        printSequence("Before :", inputVec);
        benchmarkMergeInsertionSort(inputVec.begin(), inputVec.end(), "std::vector");
        printSequence("After  :", inputVec);

        benchmarkMergeInsertionSort(inputDeque.begin(), inputDeque.end(), "std::deque");
        
        benchmarkMergeInsertionSort(inputList.begin(), inputList.end(), "std::list");


    } catch (const std::exception& e) 
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}