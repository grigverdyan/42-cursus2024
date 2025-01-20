#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
public:
    Brain();
    ~Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);

private:
    std::string ideas_[100];
};

#endif // BRAIN_HPP