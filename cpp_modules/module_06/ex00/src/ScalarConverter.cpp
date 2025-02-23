#include "ScalarConverter.hpp"

#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cstdlib>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& /* other */) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& /* rhs */) { return *this; }

ScalarConverter::~ScalarConverter() {}


void ScalarConverter::convert(const std::string& literal)
{
	if (std::isprint(literal[0]) && !std::isdigit(literal[0]))
	{
		if (literal.length() == 1)
			castToChar(literal);
		else if (literal == "-inf" || literal == "-inff" 
					|| literal == "+inf" || literal == "+inff"
					|| literal == "inf" || literal == "inff")
			inf(literal);
		else if (literal == "nan" || literal == "nanf")
			nan();
		else
			allImpossible();
	}
	else if (literal[literal.length() - 1] == 'f')
	{
		unsigned long int i = 0;
		while (i < literal.length() - 1 && (std::isdigit(literal[i]) || literal[i] == '.'))
			++i;
		if (i == literal.length() - 1)
			castToFloat(literal);
		else
			allImpossible();
	}
	else if (literal.find('.') != std::string::npos)
	{
		unsigned long int i = 0;
		while (std::isdigit(literal[i]) || literal[i] == '.')
			++i;
		if (i == literal.length())
			castToDouble(literal);
		else
			allImpossible();
	}
	else if (std::isdigit(literal[0]))
	{
		unsigned long int i = 0;
		while (std::isdigit(literal[i]))
			++i;
		if (i == literal.length())
			castToInt(literal);
		else
			allImpossible();
	}
	else
		allImpossible();
}




void ScalarConverter::inf(const std::string& literal)
{
	if (literal == "-inf" || literal == "-inff") 
    {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << INT_MIN << std::endl;
		std::cout << "float: " << FLT_MIN << std::endl;
		std::cout << "double: " << DBL_MIN << std::endl;
	}
    else
    {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << INT_MAX << std::endl;
		std::cout << "float: " << FLT_MAX << std::endl;
		std::cout << "double: " << DBL_MAX << std::endl;
	}
}

void ScalarConverter::nan()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void ScalarConverter::allImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::castToChar(const std::string& literal)
{
	std::cout << "char: " << literal[0] << std::endl;
	std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(literal[0]) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(literal[0]) << std::endl;
}

void ScalarConverter::castToInt(const std::string& literal)
{
	long long	num = atol(literal.c_str());

	if (num < 0 || num > 127)
		std::cout << "char: impossible" << std::endl;
	else if (num < 32 || num == 127)
    {
		std::cout << "char: Non displayable" << std::endl;
    }
    else
	{
      	std::cout << "char: " << static_cast<char>(num) << std::endl;
    }

	if (num > INT_MAX || num < INT_MIN)
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
    	std::cout << "int: " << static_cast<int>(num) << std::endl;
	}	
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}

void ScalarConverter::castToFloat(const std::string& literal)
{
	float num = atof(literal.c_str());

	if (num < 0 || num > 127)
	{	
        std::cout << "char: impossible" << std::endl;
    }
    else if (num < 32 || num == 127)
	{
        std::cout << "char: non-displayable" << std::endl;
    }
    else
	{	
        std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
    }
	if (num > INT_MAX || num < INT_MIN)
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
    	std::cout << "int: " << static_cast<int>(num) << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << num << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}

void ScalarConverter::castToDouble(const std::string& literal)
{
	double num = atof(literal.c_str());

	if (num < 0 || num > 127)
	{	
        std::cout << "char: impossible" << std::endl;
    }
    else if (num < 32 || num == 127)
	{
        std::cout << "char: non-displayable" << std::endl;
    }
    else
	{
        std::cout << "char: " << static_cast<char>(num) << std::endl;
    }

	if (num > INT_MAX || num < INT_MIN)
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
    	std::cout << "int: " << static_cast<int>(num) << std::endl;
	}	
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << num << std::endl;
}