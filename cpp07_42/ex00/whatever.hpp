#ifndef MAIN_HPP
# define MAIN_HPP

#include <iostream>
#include <cstring>

template <class C>
void	swap(C &a, C &b)
{
	C c = a;
	a = b;
	b = c;
}

template <class C>
C &min(C &a, C &b)
{
	if (b > a)
		return (a);
	return (b);
}

template <class C>
C &max(C &a, C &b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif
