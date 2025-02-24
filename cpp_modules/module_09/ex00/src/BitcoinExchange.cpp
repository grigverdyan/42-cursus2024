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


void BitcoinExchange::loadData(const std::string& inputFile)
{
    std::ifstream file(inputFile);
    if (!file.is_open())
    {
        std::cerr << "Error: Cannot open database file " << inputFile << "." << std::endl;
        return;
    }

    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date;
        std::string value;
        iss >> date >> value;

        if (iss.fail())
        {
            std::cerr << "Error: Invalid line in file " << inputFile << std::endl;
            continue;
        }



        try 
        {
            if (value.find('.') != std::string::npos)
            {
                int num = convertString<int>(value);
                data_[date] = num;
            }
            else
            {
                float num = convertString<float>(value);
                data_[date] = num;
            }
        }
        catch (std::exception& e)
        {
            std::cerr << "Error: " << e.what();
        }
    }

    file.close();

    // Iterate through the map using iterators
    std::map<std::string, float>::iterator it;
    for (it = data_.begin(); it != data_.end(); ++it) {
        std::cout << "Date: " << it->first << ", Value: " << it->second << std::endl;
    }
}

void BitcoinExchange::evaluateFile(const std::string& inputFile)
{
   (void)inputFile;
}
