#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <class C>
void	iter(C *tab, int len, void (*func)(C&))
{
	for (int i = 0; i < len; i++)
	{
		func(tab[i]);
	}
}

#endif