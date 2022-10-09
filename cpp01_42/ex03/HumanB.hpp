

#ifndef HUMANB_HPP
#define HUMANB_HPP


#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon	*_Weapon;
	public:
		HumanB( std::string Name );
		~HumanB();
		void	attack();
		std::string	getName();
		void	setName(std::string name);
		void	setWeapon(Weapon &Weapon);
};

#endif