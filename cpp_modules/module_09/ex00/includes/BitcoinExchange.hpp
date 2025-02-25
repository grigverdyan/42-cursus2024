#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <sstream>

// Type Specialization at compile-time
template<typename T>
struct TypePrinter
{
    static const char* getType() { return "Unknown"; }
};

template<>
struct TypePrinter<int>
{
    static const char* getType() { return "Integer"; }
};

template<>
struct TypePrinter<double>
{
    static const char* getType() { return "Double"; }
};

class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(const std::string& fbFile);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void evaluateFile(const std::string& inputFile);

private:
    void loadData(const std::string& inputFile);

    template<typename T>
    T convertString(const std::string& str) const
    {
        std::istringstream iss(str);
        T num;
        if (!(iss >> num))
        {
            throw std::runtime_error("Invalid " + std::string(TypePrinter<T>::getType()) + " format in the input file!");
        }
        return num;
    }

    bool validateDate(const std::string& date);

private:
    std::map<std::string, double> data_;
};

#endif