#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>


std::vector<int> getArguments(int argc, char* argv[])
{
	std::vector<int> range;

	for (int i = 1; i < argc; ++i)
	{
		int num = std::atoi(argv[i]);
		if (num <= 0)
		{
			throw std::invalid_argument("Error: not positive integer is provided.");
		}
		range.push_back(std::atoi(argv[i]));
	}
	return range;
}