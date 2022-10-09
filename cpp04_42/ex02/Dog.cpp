#include "Dog.hpp"

Dog::Dog() 
{
	std::cout << "Dog: Default constructor called" << std::endl;
	this->_brain = new Brain();
	this->_type = "Dog";
}

Dog::Dog(const Dog &src) : Animal() 
{
	std::cout << "Dog: Copy constructor called" << std::endl;
	*this = src;
}

void Dog::makeSound() const 
{
	std::cout << "Woof!" << std::endl;
}

Dog::~Dog() 
{
	std::cout << "Dog: Destructor called" << std::endl;
	delete this->_brain;
}

Brain *Dog::getBrain() const 
{
	return this->_brain;
}

Dog		&Dog::operator=( Dog const &src )
{
	std::cout << "Dog: Assignement operator called" << std::endl;
	this->_type = src.getType();
	*this->_brain = *src.getBrain();
	return *this;
}
Animal	&Dog::operator=( Animal const &src )
{
	std::cout << "Dog: Animal Assignement operator called" << std::endl;
	this->_type = src.getType();
	*this->_brain = *src.getBrain();
	return *this;
}
