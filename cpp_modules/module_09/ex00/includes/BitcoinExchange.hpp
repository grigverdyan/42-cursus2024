#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <sstream>
#include <iostream>

struct Bitcoin
{
    std::string date;
    double      rate;

    Bitcoin() : date(""), rate(-1) {}
    ~Bitcoin() {}
    Bitcoin(const Bitcoin&) {} 
    Bitcoin& operator=(const Bitcoin&) { return *this; } 
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

    double convertString(const std::string& str) const;
    bool validateDate(const std::string& date);
    Bitcoin extractDateValue(const std::string& line, char delimiter);

private:
    std::map<std::string, double> data_;
};

#endif