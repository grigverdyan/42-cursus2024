#include <iostream>

#include "Serializer.hpp"

int main()
{
    Data* data = new Data(42);
    uintptr_t ptr;

    std::cout << data << std::endl;

    ptr = Serializer::serialize(data);

    std::cout << ptr << std::endl;

    Data* deserializedData = Serializer::deserialize(ptr);

    std::cout << deserializedData << std::endl;

    if (data == deserializedData) 
	{
        std::cout << "Success: The original and deserialized Data objects are the same." << std::endl;
    } 
	else 
	{
        std::cout << "Error: The original and deserialized Data objects are different." << std::endl;
    }

    delete data;
	
    return 0;
}