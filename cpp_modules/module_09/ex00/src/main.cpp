#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
    if (argc < 2 || argc > 3) 
    {
        std::cerr << "Usage: " << argv[0] << " <input_file> [<database_file.csv>]" << std::endl;
        return 1;
    }

    std::string inputFile = argv[1];
    std::string dbFile = "data.csv";
    if (argc != 2)
    {
        dbFile = argv[2];
    }

    if (dbFile.substr(dbFile.find_last_of(".") + 1) != "csv") 
    {
        std::cerr << "Error: The database file must have a .csv extension." << std::endl;
        return 1;
    }

    BitcoinExchange exchange(dbFile);
    exchange.evaluateFile(inputFile);

    return 0;
}