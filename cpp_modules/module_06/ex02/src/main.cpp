#include "identify_functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>

int main()
{
    Base* ptr1 = generate();
    identify(ptr1);
    delete ptr1;

    std::cout << std::endl;

    Base* ptr2 = new A;
    identify(ptr2);
    delete ptr2;

	std::cout << std::endl;

    Base* ptr3 = new B;
    identify(ptr3);
    delete ptr3;

	std::cout << std::endl;

    Base* ptr4 = new C;
    identify(ptr4);
    delete ptr4;

    return 0;
}