#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span
{
public:
	Span();
    Span(unsigned int N);
    ~Span();
    Span(const Span& other);
    Span& operator=(const Span& other);
	
    void addNumber(int number);
	void printSpan() const;
	void fillSpan(unsigned int size);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

	template <typename T>
	void addNumberRange(typename T::iterator begin, typename T::iterator end)
	{
		unsigned int distance = std::distance(begin, end);

		if (distance > (this->N_ - numbers_.size()))
        {
			throw SpanIsFullException();
        }
        numbers_.insert(numbers_.end(), begin, end);
	}
	
public:
	struct SpanIsFullException : public std::exception
	{
		virtual const char* what() const throw();
	};

	struct RangeTooSmallException : public std::exception
	{
		virtual const char* what() const throw();
	};

private:
    unsigned int        N_;
    std::vector<int>    numbers_;
};

#endif // SPAN_HPP