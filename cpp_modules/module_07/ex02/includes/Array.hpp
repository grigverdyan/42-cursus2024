#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
// Exception class
public:
	struct OutOfBoundsException : public std::exception
	{
        const char* what() const throw()
		{
            return "Index out of bounds";
        }
    };

public:
    Array() 
        : data_(NULL)
        , len_(0)
    {}

    Array(unsigned int n) 
        : len_(n)
	{
        data_ = new T[n];
    }

    Array(const Array& other) 
        : len_(other.len_)
	{
        data_ = new T[len_];
        for (size_t i = 0; i < len_; ++i) 
        {
            data_[i] = other.data_[i];
        }
    }

    Array& operator=(const Array& other)
	{
        if (this != &other)
        {
            len_ = other.len_;
            T* tmp = new T[len_];
            for (size_t i = 0; i < len_; ++i) 
            {
                tmp[i] = other.data_[i];
            }
            
            delete[] data_;
            data_ = tmp;
        }
        return *this;
    }

    ~Array()
	{
        delete[] data_;
    }

    T& operator[](size_t index)
	{
        if (index >= len_) {
            throw OutOfBoundsException();
        }
        return data_[index];
    }

    const T& operator[](size_t index) const
	{
        if (index >= len_) {
            throw OutOfBoundsException();
        }
        return data_[index];
    }

    size_t size() const
	{
        return len_;
    }

private:
    T*      data_;
    size_t  len_;
};

#endif // ARRAY_HPP