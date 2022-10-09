#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat: Default constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal() {
	std::cout << "WrongCat: Copy constructor called" << std::endl;
	*this = src;
}

void WrongCat::makeSound() const {
	std::cout << "mioumiou" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat: Destructor called" << std::endl;
}
