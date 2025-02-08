#include "identify_functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime> 

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "The pointer is of type A." << std::endl;
    
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "The pointer is of type B." << std::endl;

        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "The pointer is of type C." << std::endl;
    }
    catch (const std::exception&) {}
}

void identify(Base* p)
{
    if (!p) 
    {
        std::cout << "The pointer is null." << std::endl;
        return;
    }

    A* a = dynamic_cast<A*>(p);
    if (a)
    {
        std::cout << "The pointer is of type A." << std::endl;
    }
    
    B* b = dynamic_cast<B*>(p);
    if (b)
    {
        std::cout << "The pointer is of type B." << std::endl;
    }
    
    C* c = dynamic_cast<C*>(p);
    if (c)
    {
        std::cout << "The pointer is of type C." << std::endl;
    }
}

Base* generate()
{
	Base* ptr = NULL;

	srand(time(0));
	int num = rand() % 3;
	
    if (num == 0) 
    {
        ptr = new A;
        std::cout << "A created." << std::endl;
    } 
    else if (num == 1) 
    {
        ptr = new B;
        std::cout << "B created." << std::endl;
    } 
    else 
    {
        ptr = new C;
        std::cout << "C created." << std::endl;
    }
    return ptr;
}