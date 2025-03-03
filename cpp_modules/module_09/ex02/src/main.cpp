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
        if (argc < 2) {
            throw std::invalid_argument("Usage: ./PmergeMe \"Range of positive integers\"");
        }
        std::vector<int> input = getArguments(argc, argv);

        std::vector<int> inputVec;
        std::copy(input.begin(), input.end(), std::back_inserter(inputVec));
        std::deque<int> inputDeque(inputVec.begin(), inputVec.end());
        std::list<int> inputList(inputVec.begin(), inputVec.end());

        printSequence("\n**Before : ", inputVec);
        benchmarkMergeInsertionSort(input, false);
        printSequence("\n***After : ", input);
        
        benchmarkMergeInsertionSort(inputVec);
        printSequence("\nSorted using vector : ", inputVec);

        benchmarkMergeInsertionSort(inputDeque);
        printSequence("\nSorted using Deque : ", inputDeque);
        
        benchmarkMergeInsertionSort(inputList);
        printSequence("\nSorted using List : ", inputList);

    } catch (const std::exception& e) 
    {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
        return 1;
    }

    return 0;
}