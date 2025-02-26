#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>


std::vector<int> getArguments(int argc, char* argv[])
{

	std::string numbers;
	for (int i = 1; i < argc; ++i)
	{
		numbers += std::string(argv[i]) + " ";
	}

	std::stringstream ss(numbers);
	std::string num;
	std::vector<int> range;
	while (std::getline(ss, num, ' '))
	{
		if (num.find_first_not_of("0123456789") != std::string::npos)
		{
			throw std::invalid_argument("Error: not an integer is provided.");
		}
		long number = stringToInt()(num);
		if (number > std::numeric_limits<int>::max()) {
			throw std::invalid_argument("Error: too large integer is provided.");
		}
		if (number <= 0)
		{
			throw std::invalid_argument("Error: not positive integer is provided.");
		}
		range.push_back(number);
	}
	
	return range;
}