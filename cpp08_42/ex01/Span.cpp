#include "Span.hpp"

Span::Span(unsigned int N): size(N)
{
	std::cout << "constructor called" << std::endl;
}

Span::Span(const Span &src)
{
	std::cout << "cpy constructor called" << std::endl;
	*this = src;
}

Span &Span::operator=(const Span &src) {
	std::cout << "Assignement operator called" << std::endl;
	this->vec.clear();
	for (unsigned long i = 0; i < src.vec.size(); i++)
		this->vec.push_back(src.vec[i]);
	return *this;
}

Span::~Span()
{
	std::cout << "Destructor called" << std::endl;
	this->vec.clear();
}

void	Span::addNumber(int nbr)
{
	if (this->vec.size() >= this->size)
		throw std::length_error("can't add more number");
	this->vec.push_back(nbr);
}

int Span::shortestSpan()
{
	if (this->vec.size() < 2)
		throw std::length_error("can't find shortest if less than 2 val");
	int shortest = INT_MAX;
	std::vector<int> tmp = this->vec;
	std::sort(tmp.begin(), tmp.end());
	std::vector<int>::iterator iterator = tmp.begin();
	while ((iterator + 1) != tmp.end()) {
		if (*(iterator + 1) - *iterator < shortest)
			shortest = *(iterator + 1) - *iterator;
		iterator++;
	}
	return (shortest);
}

int	Span::longestSpan()
{
	if (this->vec.size() < 2)
		throw std::length_error("can't fine longestspan if less than 2 val");
	std::vector<int> tmp = this->vec;
	std::sort(tmp.begin(), tmp.end());
	return *(tmp.end() - 1) - *tmp.begin();
}

void	Span::iteratorFiller(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	if (this->size - this->vec.size() <= 0)
		throw std::length_error("can't add that many integers");
	copy(start, end, std::back_inserter(this->vec));
}

void	Span::randomFiller()
{
	while (this->vec.size() < this->size)
	{
		this->vec.push_back(rand());
	}
}