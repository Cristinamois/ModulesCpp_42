#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref) {
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed::Fixed(const float d) {
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(d * std::pow(2, this->_fractBits));
}

Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = i << this->_fractBits;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &rhs)
		this->_rawBits = rhs._rawBits;
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}

int Fixed::toInt() const {
	return (this->_rawBits / pow(2, this->_fractBits));
}

float Fixed::toFloat() const {
	return (this->_rawBits / pow(2, this->_fractBits));
}