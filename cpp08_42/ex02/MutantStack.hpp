#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <clocale>
#include <algorithm>
#include <iostream>

template<class T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
    public:
        typedef typename Container::iterator iterator;

        MutantStack(): std::stack<T, Container>() {}
        ~MutantStack() {}
        MutantStack &operator=(const MutantStack &src)
        {
            this->c = src.c;
            return(*this);
        }
        iterator    begin(void)
        {
            return(this->c.begin());
        }
        iterator    end(void)
        {
            return (this->c.end());
        }
};

#endif