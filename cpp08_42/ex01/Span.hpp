#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <ctime>


class Span
{
	private:
		unsigned int size;
		std::vector<int> vec;
	public:
		Span(unsigned int N);
		Span(const Span &src);
		Span &operator=(const Span &rhs);
		virtual ~Span();
		void addNumber(int nbr);
		int shortestSpan();
		int longestSpan();
		void iteratorFiller(std::vector<int>::iterator start, std::vector<int>::iterator end);
		void randomFiller();

};

#endif