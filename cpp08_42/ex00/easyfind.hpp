#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>

class	NotFoundException: public std::exception
{
	virtual const char * what() const throw()
	{
		return "Did not find what you're looking for :/";
	}
};

template<typename T>
typename T::iterator easyfind(T &container, int toFind)
{
	typename T::iterator res = find(container.begin(), container.end(), toFind);
	if (res == container.end())
		throw NotFoundException();
	return (res);
}

#endif