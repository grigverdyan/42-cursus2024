#include <iostream>
#include <vector>
#include <list>

#include "easyfind.hpp"

template <typename Cont>
void ContainerCheck(Cont &container, int value)
{
    try
    {
        typename Cont::iterator pos = easyfind(container, value);
        std::cout << "Found " << value << " at position: " << std::distance(container.begin(), pos) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(9);
    vec.push_back(10);

    ContainerCheck(vec, 7);
    ContainerCheck(vec, 42);
    std::cout << std::endl;

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);
    
    ContainerCheck(lst, 40);
    ContainerCheck(lst, 100);
    std::cout << std::endl;

    std::vector<int> empty;
    ContainerCheck(empty, 13);

    return 0;
}