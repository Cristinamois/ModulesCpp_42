#include "Animal.hpp"

Animal::Animal() : _type("Default Animal") 
{
	std::cout << "Animal Constructed called" << std::endl;
}

Animal::Animal(const Animal &src) 
{
	std::cout << "Anima: Copy constructor called" << std::endl;
	*this = src;
}

Animal &Animal::operator=(const Animal &src) 
{
	std::cout << "Animal: Assignement operator called" << std::endl;
	this->_type = src._type;
	return *this;
}

Animal::~Animal() 
{
	std::cout << "Animal: Destructor called" << std::endl;
}

void Animal::makeSound() const 
{
	std::cout << "* insert animal noise *" << std::endl;
}

const std::string &Animal::getType() const {
	return this->_type;
}
