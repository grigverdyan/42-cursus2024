#include <ctime>
#include <cstdlib>

#include "PmergeMe.hpp"

void runSortingAlgorithm(int argc, char* argv[])
{
    std::vector<int> vec;
    std::deque<int> deq;

	for (int i = 1; i < argc; ++i) 
    {
		int num = atoi(argv[i]);
		if (num <= 0) 
        {
			throw std::invalid_argument("Only positive integers are allowed.");
		}
		vec.push_back(num);
		deq.push_back(num);
	}

	std::cout << "Unsorted sequence: ";
	for (size_t i = 0; i < vec.size(); ++i) 
    {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	clock_t start = clock();
	mergeInsertionSort(vec);
	clock_t end = clock();
	double vecDuration = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	std::cout << "Sorted sequence (vector): ";
	for (size_t i = 0; i < vec.size(); ++i) 
    {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	start = clock();
	mergeInsertionSort(deq);
	end = clock();
	double deqDuration = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	std::cout << "Sorted sequence (deque): ";
	for (size_t i = 0; i < deq.size(); ++i) 
    {
		std::cout << deq[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Time taken for vector sort: " << vecDuration << " seconds" << std::endl;
	std::cout << "Time taken for deque sort: " << deqDuration << " seconds" << std::endl;
}