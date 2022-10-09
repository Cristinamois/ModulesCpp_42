
#ifndef FIXED_HPP
# define FIXED_HPP


#include <iostream>
#include <string>

class Fixed
{
    private:
        int _nbrFixe;
        static const int _frac_bits = 8;
    public:
        Fixed();
        Fixed(const Fixed &lol);
        Fixed & operator = (const Fixed &lol);   //	surcharge d'operateur, affecter valeur a =
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);

};

#endif