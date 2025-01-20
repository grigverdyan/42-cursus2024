#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
    const int animalCount = 14;
    Animal* animals[animalCount];

    for (int i = 0; i < animalCount / 2; ++i) 
    {
        animals[i] = new Dog();
    }

    for (int i = animalCount / 2; i < animalCount; ++i) 
    {
        animals[i] = new Cat();
    }

    std::cout << std::endl;

    for (int i = 0; i < animalCount; ++i) 
    {
        animals[i]->makeSound();
    }

    std::cout << std::endl;

    for (int i = 0; i < animalCount; ++i) {
        delete animals[i];
    }

    return 0;
}