#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Default WrongAnimal") {
	std::cout << "WrongAnimal: Constructed called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
	std::cout << "WrongAnimal: Copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rep) {
	this->_type = rep._type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal: Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "Slurp" << std::endl;
}

const std::string &WrongAnimal::getType() const {
	return this->_type;
}
