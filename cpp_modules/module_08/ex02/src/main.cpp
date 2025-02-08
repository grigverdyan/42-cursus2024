#include "MutantStack.hpp"

#include <list>

int main()
{
    std::cout << "Tests with MutantStack" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator stItStart = mstack.begin();
	MutantStack<int>::iterator stItEnd = mstack.end();

	++stItStart;
	--stItStart;

	while (stItStart != stItEnd)
	{
		std::cout << *stItStart << std::endl;
		++stItStart;
	}

    std::cout << std::endl << "Reversed" << std::endl;
    MutantStack<int>::const_reverse_iterator stRItStart = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator stRItEnd = mstack.rend();
    while(stRItStart != stRItEnd)
    {
        std::cout << *stRItStart << std::endl;
        ++stRItStart;
    }

    std::stack<int> s(mstack);

	std::cout << std::endl << std::endl;

    std::cout << "Tests with std::list" << std::endl;

	// Tests with list
    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(17);

    std::cout << lst.back() << std::endl;

    lst.pop_back();

    std::cout << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator lstItStart = lst.begin();
    std::list<int>::iterator lstItEnd = lst.end();

    ++lstItStart;
    --lstItStart;

    while (lstItStart != lstItEnd)
    {
        std::cout << *lstItStart << std::endl;
        ++lstItStart;
    }

    std::cout << std::endl << "Reversed" << std::endl;
    std::list<int>::const_reverse_iterator lstRItStart = lst.rbegin();
    std::list<int>::const_reverse_iterator lstRItEnd = lst.rend();
    while(lstRItStart != lstRItEnd)
    {
        std::cout << *lstRItStart << std::endl;
        ++lstRItStart;
    }

    return 0;
}