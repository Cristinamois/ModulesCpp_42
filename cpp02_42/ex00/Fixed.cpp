
#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_nbrFixe = 0;										//init nbr virugle fixe
}

Fixed::Fixed(const Fixed &lol)
{
    std::cout << "Copy constructor called" << std::endl;		//copy constructor
    this->_nbrFixe = lol.getRawBits();
}

Fixed & Fixed::operator=(const Fixed &lol)
{
    std::cout << "Copy assignment operator called" << std::endl;	//https://waytolearnx.com/2019/09/surcharge-de-loperateur-daffectation-en-cpp.html
    if (this == &lol)
        return *this;
    this->_nbrFixe = lol.getRawBits();			//gives to nbrfixe value of lol.getrawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_nbrFixe);
}

void Fixed::setRawBits(int const chaire)
{
    this->_nbrFixe = chaire;							//sets nbrfixe to chaire
}