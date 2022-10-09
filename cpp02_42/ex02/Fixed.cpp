#include "Fixed.hpp"

Fixed::Fixed() : _nbrFixe(0) 
{
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref) 
{
//	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed::Fixed(const float d) 
{
//	std::cout << "Float constructor called" << std::endl;
	this->_nbrFixe = roundf(d * std::pow(2, _frac_Bits));
}

Fixed::Fixed(const int i) 
{
//	std::cout << "Int constructor called" << std::endl;
	this->_nbrFixe = i << _frac_Bits;
}

Fixed::~Fixed() 
{
//	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src2) 
{
//	std::cout << "Assignement operator called" << std::endl;
	if (this != &src2)
		this->_nbrFixe = src2._nbrFixe;
	return *this;
}

int Fixed::getRawBits() const 
{
	return this->_nbrFixe;
}

void Fixed::setRawBits(const int raw) 
{
	this->_nbrFixe = raw;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) 
{
	if (fixed.toFloat() - fixed.toInt() > 0)
		os << fixed.toFloat();
	else
		os << fixed.toInt();
	return os;
}

int Fixed::toInt() const 
{
	return (this->_nbrFixe / pow(2, _frac_Bits));
}

float Fixed::toFloat() const {
	return (this->_nbrFixe / pow(2, _frac_Bits));
}
bool Fixed::operator>(const Fixed &src2) const 
{
	return (this->_nbrFixe > src2._nbrFixe);
}

bool Fixed::operator<(const Fixed &src2) const 
{
	return (this->_nbrFixe < src2._nbrFixe);
}

bool Fixed::operator>=(const Fixed &src2) const 
{
	return (this->_nbrFixe >= src2._nbrFixe);
}

bool Fixed::operator<=(const Fixed &src2) const 
{
	return (this->_nbrFixe <= src2._nbrFixe);
}

bool Fixed::operator==(const Fixed &src2) const 
{
	return (this->_nbrFixe == src2._nbrFixe);
}

bool Fixed::operator!=(const Fixed &src2) const 
{
	return !(src2 == *this);
}

Fixed Fixed::operator+(const Fixed &src2) const 
{
	return Fixed(toFloat() + src2.toFloat());
}

Fixed Fixed::operator-(const Fixed &src2) const 
{
	return Fixed(toFloat() - src2.toFloat());
}

Fixed Fixed::operator*(const Fixed &src2) const 
{
	return Fixed(toFloat() * src2.toFloat());
}

Fixed Fixed::operator/(const Fixed &src2) const 
{
	return Fixed(toFloat() / src2.toFloat());
}

Fixed &Fixed::operator++(void) 
{
	++this->_nbrFixe;
	return *this;
}

Fixed Fixed::operator++(int) 
{
	Fixed old(*this);
	++this->_nbrFixe;
	return old;
}

Fixed &Fixed::operator--(void) 
{
	--this->_nbrFixe;
	return *this;
}

Fixed Fixed::operator--(int) 
{
	Fixed old(*this);
	--this->_nbrFixe;
	return old;
}

Fixed &Fixed::min(Fixed &src, Fixed &src2) 
{
	if (src > src2)
		return (src2);
	return (src);
}

const Fixed &Fixed::min(const Fixed &src, const Fixed &src2) 
{
	if (src > src2)
		return (src2);
	return (src);
}

Fixed &Fixed::max(Fixed &src, Fixed &src2) 
{
	if (src > src2)
		return (src);
	return (src2);
}

const Fixed &Fixed::max(const Fixed &src, const Fixed &src2) 
{

	if (src > src2)
		return (src);
	return (src2);
}
