#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const std::string& dbFile)
{
    loadData(dbFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : data_(other.data_)
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        data_ = other.data_;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

double BitcoinExchange::convertString(const std::string& str) const
{
    std::istringstream iss(str);
    double num;
    if (!(iss >> num))
    {
        throw std::runtime_error("Invalid float format in the input file!");
    }
    if (num < 0 || num > 1000)
    {
        std::cerr << "Error: not a positive number of [0, 1000] range. Using Default: -1." << std::endl;
        num = -1;
    }

    return num;
}

bool BitcoinExchange::validateDate(const std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') 
    {
        return false;
    }
    
    int year, month, day;
    std::istringstream ssYear(date.substr(0, 4));
    std::istringstream ssMonth(date.substr(5, 2));
    std::istringstream ssDay(date.substr(8, 2));

    if (!(ssYear >> year) || !(ssMonth >> month) || !(ssDay >> day)) 
    {
        return false;
    }

    if (year < 1 || month < 1 || month > 12 || day < 1) 
    {
        return false;
    }

    static const int daysInMonth[] = { 
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 
    };

    int maxDays = daysInMonth[month - 1];
    if (month == 2 && 
            ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) )
    {
        maxDays = 29;
    }

    return day <= maxDays;
}

Bitcoin BitcoinExchange::extractDateValue(const std::string& line, char delimiter)
{
    std::istringstream iss(line);
    std::string date;
    std::string value;
    
    std::getline(iss >> std::ws, date, delimiter);
    iss >> value;

    if (iss.fail() || line.find(line.begin(), line.end(), "|") == line.end())
    {
        std::cerr << "Error: Invalid line in file " << inputFile << std::endl;
        return NULL; 
    }

    Bitcoin bc;

    // std::cout << date << " " << value << std::endl;
    if (!validateDate(date))
    {
        std::cerr << "Error: Invalid date: " << date << ". Will be replaced by \"\"." << std::endl;
        bc.date = "";
    }
    else
    {
        bc.date = date;
    }

    try 
    {
        bc.rate = convertString(value);
    }
    catch (std::exception& e)
    {
        std::cerr << "Error: " << e.what();
        bc.rate= -1;
        return bc; 
    }

    return bc;
}


void BitcoinExchange::loadData(const std::string& inputFile)
{
    std::ifstream file(inputFile.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: Cannot open database file " << inputFile << "." << std::endl;
        return;
    }

    std::string line;
    bool firstLine = true;

    while (std::getline(file, line))
    {
        if (firstLine)
        {
            firstLine = false;
            continue;
        }
        Bitcoin bc = extractDateValue(line, ',');
        data_[bc.date] = bc.rate;
    }

    file.close();

    // // Iterate through the map using iterators
    // std::map<std::string, double>::iterator it;
    // for (it = data_.begin(); it != data_.end(); ++it) 
    // {
    //     std::cout << "Date: " << it->first << " Value: " << it->second << std::endl;
    // }
}

void BitcoinExchange::evaluateFile(const std::string& inputFile)
{
    std::ifstream file(inputFile.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: Cannot open input file " << inputFile << "." << std::endl;
        return;
    }

    std::string line;
    bool firstLine = true;

    while (std::getline(file, line))
    {
        if (firstLine)
        {
            firstLine = false;
            continue;
        }
        Bitcoin bc = extractDateValue(line, '|');

        std::map<std::string, double>::iterator it = data_.lower_bound(bc.date);

        // If the exact date is not found, use the previous date (if available)
        if (it == data_.end() || it->first != bc.date) 
        {
            if (it != data_.begin()) 
            {
                --it;
            } 
            else 
            {
                std::cerr << "No exchange rate available for date: " << bc.date << std::endl;
                continue;
            }
        }
        double exchangeRate = it->second;
        if (exchangeRate < 0)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        double result = bc.rate * exchangeRate;

        std::cout << bc.date << " => " << bc.rate << " = " << result << std::endl;
    }

    file.close();
}
