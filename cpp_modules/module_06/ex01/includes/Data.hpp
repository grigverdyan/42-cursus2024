#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data
{
public:
    Data();
    explicit Data(int number);
    ~Data();

    Data(const Data& other);
    Data& operator=(const Data& other);

    int getNumber() const;

private:
    int number_;
};

std::ostream& operator<<(std::ostream& out, const Data& other);

#endif // DATA_HPP