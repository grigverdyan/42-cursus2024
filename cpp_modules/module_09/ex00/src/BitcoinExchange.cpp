#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>

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

double BitcoinExchange::convertString(const std::string& str, bool validateInput)
{
    std::istringstream iss(str);
    double num;

    try
    {
        if (!(iss >> num)) {
            throw std::runtime_error("Invalid float format in the input file");
        }
        if (validateInput && num > 1000) {
            throw std::runtime_error("too large a number.");
        }
        if (num < 0) {
            throw std::runtime_error("not a positive number.");
        }
    }
    catch(const std::exception& e)
    {
        if (validateInput) {
            std::cerr << "Error: " << e.what() << '\n';
        }
        num = -1;
    }

    return num;
}

bool BitcoinExchange::validateDate(const std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    
    int year, month, day;
    std::istringstream ssYear(date.substr(0, 4));
    std::istringstream ssMonth(date.substr(5, 2));
    std::istringstream ssDay(date.substr(8, 2));

    if (!(ssYear >> year) || !(ssMonth >> month) || !(ssDay >> day)) {
        return false;
    }

    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    static const int daysInMonth[] = { 
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 
    };

    int maxDays = daysInMonth[month - 1];
    if (month == 2 && 
            ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ) {
        maxDays = 29;
    }

    return day <= maxDays;
}

Bitcoin BitcoinExchange::extractDateValue(std::string& line, char delimiter, bool validateInput)
{
    std::istringstream iss(line);
    std::string date;
    std::string value;
    
    if (std::getline(iss, date, delimiter) && std::getline(iss, value)) 
    {
        if (!validateDate(date))
        {
            if (validateInput) {
                std::cerr << "Error: Invalid date format => " << date << std::endl;
            }
            return Bitcoin();
        }
        if (value.empty())
        {
            if (validateInput) {
                std::cerr << "Error: Invalid value format => " << value << std::endl;
            }
            return Bitcoin();
        }
        return Bitcoin(date, convertString(value, validateInput));
    } 
    return Bitcoin();
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
    bool formatLine = false;
    std::string format = "date,exchange_rate";

    while (std::getline(file, line))
    {
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
        if (!formatLine && !line.empty() && line.find(format) != std::string::npos && line.length() == format.length())
        {
            formatLine = true;
            continue;
        }

        if (!formatLine) {
            continue;
        }

        if (!line.empty() && line.find(',') == std::string::npos)
        {
            std::cerr << "Error: Invalid line format: " << line << " " << std::endl;
            continue;
        }
        Bitcoin bc = extractDateValue(line, ',');
        data_[bc.date] = bc.rate;
    }
    
    file.close();

    if (!formatLine) {
        throw std::runtime_error("Invalid Database file: No DB Format provided \"" + format + "\"");
    }
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
    bool formatLine = false;
    std::string format = "date|value";

    while (std::getline(file, line))
    {
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
        if (!formatLine && !line.empty() && line.find("date|value") != std::string::npos && line.length() == format.length())
        {
            formatLine = true;
            continue;
        }
        if (!formatLine) {
            continue;
        }

        if (line.find('|') == std::string::npos)
        {
            std::cerr << "Error: bad input";
            if (!line.empty()) {
                std::cerr << " => " << line;
            }
            std::cerr << std::endl;
            continue;
        }
        Bitcoin bc = extractDateValue(line, '|', true);
        if (bc.rate < 0 || bc.date.empty()) {
            continue;
        }

        std::map<std::string, double>::iterator it = data_.lower_bound(bc.date);
        if (it == data_.end() || it->first != bc.date) 
        {
            if (it != data_.begin()) {
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
            std::cerr << "Error: Invalid exchange rate for date: " << bc.date << std::endl;
            continue;
        }
        double result = bc.rate * exchangeRate;

        std::cout << bc.date << " => " << bc.rate << " = " << result << std::endl;
    }
    
    file.close();

    if (!formatLine) {
         throw std::runtime_error("Invalid Input file: No Inpuy file Format provided \"" + format + "\"");
    }
}
