#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat: Default constructor called" << std::endl;
	this->_brain = new Brain();
	this->_type = "Cat";
}

Cat::Cat(const Cat &src) : Animal() {
	std::cout << "Cat: Copy constructor called" << std::endl;
	*this = src;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat: Destructor called" << std::endl;
	delete this->_brain;
}

Brain *Cat::getBrain() const {
	return this->_brain;
}

Cat		&Cat::operator=( Cat const &src )
{
	std::cout << "Cat: Assignement operator called" << std::endl;
	this->_type = src.getType();
	*this->_brain = *src.getBrain();
	return *this;
}
Animal	&Cat::operator=( Animal const &src )
{
	std::cout << "Cat: Animal Assignement operator called" << std::endl;
	this->_type = src.getType();
	*this->_brain = *src.getBrain();
	return *this;
}