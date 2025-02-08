#include <iostream>

#include "Span.hpp"

int main()
try
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

    Span sp2 = Span(7);
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    sp2.addNumberRange<std::vector<int> >(v.begin(), v.end());

    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;

    Span sp3 = Span(3);
    std::vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(50);
    sp3.addNumberRange<std::vector<int> >(v2.begin(), v2.end());
    
	return 0;
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}