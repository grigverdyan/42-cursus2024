#include "Point.hpp"
#include <iostream>

bool bsp(const Point a, const Point b, const Point c, const Point point);

void test(const Point& a, const Point& b, const Point& c, const Point& point)
{
    std::cout << "Point" << point << std::endl 
    << "a" << a << std::endl
    << "b" << b << std::endl
    << "c" << c << std::endl;
    if (bsp(a, b, c, point))
    {
        std::cout << "\033[32mTRUE\033[0m" << "Point " << point << " is inside the triangle!\n"<< std::endl;
    }
    else
    {
        std::cout << "\033[31mFALSE\033[0m" << "Point " << point << " is not inside the triangle!\n"<< std::endl;
    }
    std::cout << "\n---------------------------------------------------------------------\n" << std::endl;
}

int main(void)
{
	{
        const Point a;
        const Point b(10, 0);
        const Point c(0, 10);
        const Point point(1, 1);

        test(a, b, c, point);
    }
	{
        Point a(-1.5, -1.5);
        Point b(2.5, 2.5);
        Point c(-1, -2);
        Point point(8.5, -9);

        test(a, b, c, point);
    }
	return (0);
}