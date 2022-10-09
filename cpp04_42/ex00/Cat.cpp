#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat: Default constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &src) : Animal() {
	std::cout << "Cat: Copy constructor called" << std::endl;
	*this = src;
}

void Cat::makeSound() const {
	std::cout << "MiAoU fdp" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat: Destructor called" << std::endl;
}
