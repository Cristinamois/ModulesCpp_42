#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed 
{
	public:
		Fixed();
		Fixed(const Fixed &ref);
		Fixed(const float d);
		Fixed(const int d);
		~Fixed();
		int getRawBits() const;
		void setRawBits(const int raw);
		int toInt() const;
		float toFloat() const;
		Fixed &operator=(const Fixed &src);
		bool operator>(const Fixed &src) const ;
		bool operator<(const Fixed &src) const ;
		bool operator>=(const Fixed &src) const ;
		bool operator<=(const Fixed &src) const ;
		bool operator==(const Fixed &src) const ;
		bool operator!=(const Fixed &src) const ;
		Fixed operator+(const Fixed &src) const ;
		Fixed operator-(const Fixed &src) const ;
		Fixed operator*(const Fixed &src) const ;
		Fixed operator/(const Fixed &src) const ;
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);
		static Fixed &min(Fixed &src, Fixed &src2);
		static const Fixed &min(const Fixed &src, const Fixed &src2);
		static Fixed &max(Fixed &src, Fixed &src2);
		static const Fixed &max(const Fixed &src, const Fixed &src2);

	private:
		int _nbrFixe;
		static const int _frac_Bits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
