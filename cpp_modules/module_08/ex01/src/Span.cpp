#include <algorithm>
#include <climits>
#include <iterator>
#include <iostream>

#include "Span.hpp"

const char* Span::SpanIsFullException::what() const throw()
{
    return "Span is full. Cannot add more numbers.";
}

const char* Span::RangeTooSmallException::what() const throw()
{
    return "Not enough numbers to compute a span.";
}

Span::Span() 
    : N_(0)
{}

Span::Span(unsigned int N) 
    : N_(N)
{}

Span::~Span() {}

Span::Span(const Span& other) 
    : N_(other.N_)
    , numbers_(other.numbers_)
{}

Span& Span::operator=(const Span& other)
{
    if (this != &other) 
    {
        N_ = other.N_;
        numbers_ = other.numbers_;
    }
    return *this;
}

void Span::printSpan() const
{
    for (size_t i = 0; i < numbers_.size(); ++i)
    {
        std::cout << numbers_[i] << " ";
    }
    std::cout << std::endl;
}

void Span::fillSpan(unsigned int size)
{
    for (size_t i = 0; i < size; ++i)
    {
        addNumber(std::rand() % 10000);
    }
}

void Span::addNumber(int number)
{
    if (numbers_.size() >= N_)
    {
        throw SpanIsFullException();
    }
    numbers_.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    if (numbers_.size() < 2)
    {
        throw RangeTooSmallException();
    }

    std::vector<int> sorted(numbers_);
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = UINT_MAX;
    for (size_t i = 1; i < sorted.size(); ++i) 
    {
        unsigned int diff = sorted[i] - sorted[i - 1];
        if (diff < minSpan)
        {
            minSpan = diff;
        }
    }

    return minSpan;
}

unsigned int Span::longestSpan() const
{
    if (numbers_.size() < 2)
    {
        throw RangeTooSmallException();
    }

    int min = *std::min_element(numbers_.begin(), numbers_.end());
    int max = *std::max_element(numbers_.begin(), numbers_.end());
    return static_cast<unsigned int>(max - min);
}