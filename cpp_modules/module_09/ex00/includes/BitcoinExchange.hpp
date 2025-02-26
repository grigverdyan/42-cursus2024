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
    Bitcoin(const std::string& d, double r) : date(d), rate(r) {}
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

    double convertString(const std::string& str, bool printException = false);
    bool validateDate(const std::string& date);
    Bitcoin extractDateValue(std::string& line, char delimiter, bool printException = false);

private:
    std::map<std::string, double> data_;
};

#endif