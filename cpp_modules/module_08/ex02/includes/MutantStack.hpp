#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>
#include <iterator>

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
public:
// Iterator types
typedef typename std::stack<T, C>::container_type::iterator iterator;
typedef typename std::stack<T, C>::container_type::const_iterator const_iterator;
typedef typename std::stack<T, C>::container_type::reverse_iterator	reverse_iterator;
typedef typename std::stack<T, C>::container_type::const_reverse_iterator const_reverse_iterator;

public:
    MutantStack()
        : std::stack<T, C>()
    {}

    MutantStack(const MutantStack& other)
        : std::stack<T, C>(other)
    {}
    
    MutantStack& operator=(const MutantStack& other)
    {
        if (this != &other)
        {
            std::stack<T, C>::operator=(other);
        }
        return *this;
    }
    ~MutantStack() {}

public:
//Iterator methods
    typename C::iterator begin() { return this->c.begin(); }
    typename C::iterator end() { return this->c.end(); }

    typename C::const_iterator begin() const { return this->c.begin(); }
    typename C::const_iterator end() const { return this->c.end(); }

    typename C::reverse_iterator rbegin() { return this->c.rbegin(); }
    typename C::reverse_iterator rend() { return this->c.rend(); }

    typename C::const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    typename C::const_reverse_iterator rend() const { return this->c.rend(); }

};

#endif // MUTANTSTACK_HPP