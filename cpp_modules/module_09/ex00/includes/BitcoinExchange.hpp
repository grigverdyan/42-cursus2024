#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

union Bitcoin
{
    int i;
    float f;
};

class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(const std::string& inputFile);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void loadData(const std::string& inputFile);
    void evaluateFile(const std::string& inputFile);


private:
    std::map<std::string, Bitcoin> data_;
};

#endif