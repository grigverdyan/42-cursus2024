#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    try 
    {
        if (argc < 2) 
        {
            throw std::invalid_argument("Please provide a sequence of positive integers.");
        }

        runSortingAlgorithm(argc, argv);
    } catch (const std::invalid_argument& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) 
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}