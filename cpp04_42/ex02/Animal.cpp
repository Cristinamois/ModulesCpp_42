#include "Animal.hpp"

Animal &Animal::operator=(const Animal &src) {
	std::cout << "Animal: Assignement operator called" << std::endl;
	this->_type = src._type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal: Destructor called" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "* insert animal noise *" << std::endl;
}

const std::string &Animal::getType() const {
	return this->_type;
}
