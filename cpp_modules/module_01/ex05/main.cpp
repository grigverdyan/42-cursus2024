#include "Harl.hpp"

#include <iostream>

int main()
{
	Harl	harl;

	harl.complain("ERROR");
	std::cout << std::endl;

	harl.complain("WARNING");
	std::cout << std::endl;
	
    harl.complain("INFO");
	std::cout << std::endl;
	
    harl.complain("DEBUG");
	std::cout << std::endl;
	
    harl.complain("something else");
	std::cout << std::endl;

	return 0;
}