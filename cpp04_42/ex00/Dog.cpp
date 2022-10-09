#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog: Default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog &src) : Animal() {
	std::cout << "Dog: Copy constructor called" << std::endl;
	*this = src;
}

void Dog::makeSound() const {
	std::cout << "OuAf bg" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog: Destructor called" << std::endl;
}
