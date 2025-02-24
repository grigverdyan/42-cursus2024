#include "BitcoinExchange.hpp"
#include <fstream>

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const std::string& inputFile)
{
    loadData(inputFile);

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
        std::string currency;
        std::string value;
        iss >> currency >> value;

        if (iss.fail())
        {
            std::cerr << "Error: Invalid line in file " << inputFile << std::endl;
            continue;
        }

        Bitcoin bitcoin;
        if (value.find('.') != std::string::npos)
        {
            bitcoin.f = std::stof(value);
        }
        else
        {
            bitcoin.i = std::stoi(value);
        }

        data_[currency] = bitcoin;
    }

    file.close();
}

void BitcoinExchange::evaluateFile(const std::string& inputFile)
{
    std::ifstream file(inputFile);
    if (!file.is_open())
    {
        std::cerr << "Error: Cannot open file " << inputFile << std::endl;
        return;
    }

    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string currency;
        std::string value;
        iss >> currency >> value;

        if (iss.fail())
        {
            std::cerr << "Error: Invalid line in file " << inputFile << std::endl;
            continue;
        }

        Bitcoin bitcoin;
        if (value.find('.') != std::string::npos)
        {
            bitcoin.f = std::stof(value);
        }
        else
        {
            bitcoin.i = std::stoi(value);
        }

        data_[currency] = bitcoin;
    }

    file.close();
}
