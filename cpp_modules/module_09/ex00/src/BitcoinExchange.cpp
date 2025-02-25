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

Bitcoin BitcoinExchange::extractDateValue(const std::string& line)
{
    std::istringstream iss(line);
    std::string date;
    std::string value;
    std::getline(iss, date, ',');
    std::getline(iss, value, ',');

    // if (iss.fail())
    // {
    //     std::cerr << "Error: Invalid line in file " << inputFile << std::endl;
    //     return BitcoinRate("", 0); 
    // }

    Bitcoin bc;


    std::cout << date << " " << value << std::endl;
    if (!validateDate(date))
    {
        std::cerr << "Error: Invalid date format in file " << inputFile << std::endl;
        bc.date = "";
    }
    else
    {
        bc.date = date;

    }

    try 
    {
        if (value.find('.') != std::string::npos)
        {
            bc.rateType = Bitcoin::FLOAT;
            bc.rate.f = convertString<float>(value);
        }
        else
        {
            bc.rateType = Bitcoin::INT;
            bc.rate.i = convertString<int>(value);
        }
    }
    catch (std::exception& e)
    {
        std::cerr << "Error: " << e.what();
        return BitcoinRate(date, 0); 
    }

    if (num < 0 || num > 1000)
    {
        std::cerr << "Error: not a positive number of [0, 1000] range." << inputFile << std::endl;
        return BitcoinRate(date, 0); 
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

        // std::istringstream iss(line);
        // std::string date;
        // std::string value;
        // std::getline(iss, date, ',');
        // std::getline(iss, value, ',');

        // std::cout << date << " " << value << std::endl;
        // if (!validateDate(date))
        // {
        //     std::cerr << "Error: Invalid date format in file " << inputFile << std::endl;
        //     continue;
        // }

        // if (iss.fail())
        // {
        //     std::cerr << "Error: Invalid line in file " << inputFile << std::endl;
        //     continue;
        // }

        // try 
        // {
        //     ExchangeRate num;
        //     if (value.find('.') != std::string::npos)
        //     {
        //         num.iValue = convertString<int>(value);
        //         data_[date] = num;
        //     }
        //     else
        //     {
        //         num.fValue = convertString<double>(value);
        //         data_[date] = num;
        //     }
        // }
        // catch (std::exception& e)
        // {
        //     std::cerr << "Error: " << e.what();
        // }
        Bitcoin bc = extractDateValue(line);
        if (bc.rateType == Bitcoin::INT)
        {
            data_[bc.date] = bc.rate.i;
        }
        else
        {
            data_[bc.date] = bc.rate.f;
        }
    }

    file.close();

    // Iterate through the map using iterators
    std::map<std::string, double>::iterator it;
    for (it = data_.begin(); it != data_.end(); ++it) 
    {
        std::cout << "Date: " << it->first << ", Value: " << it->second << std::endl;
    }
}

void BitcoinExchange::evaluateFile(const std::string& inputFile)
{
   (void)inputFile;
}
