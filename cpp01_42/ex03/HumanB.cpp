
#include "HumanB.hpp"


HumanB::HumanB(std::string Name): _name(Name), _Weapon(NULL) {}

HumanB::~HumanB()
{
	std::cout << "HumanB Destructor\n";
}

std::string	HumanB::getName()
{
	return (this->_name);
}

void	HumanB::setName(std::string name)
{
	this->_name = name;
}

void	HumanB::attack()
{
	if (this->_Weapon != NULL)
		std::cout << this->getName() << " attacks with his " << _Weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &Weapon)
{
	this->_Weapon = &Weapon;
}