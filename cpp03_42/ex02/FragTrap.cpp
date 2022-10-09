#include "FragTrap.hpp"

void	FragTrap::highFivesGuys()
{
	std::cout << "HIGH FIVE ?!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoint = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap: " << name << " constructor called." << std::endl;
}


FragTrap::~FragTrap()
{
	if (!this->_hitPoint)
	{
		std::cout << this->_name << " wanted to high five but is dead :/" << std::endl;
		return ;
	}
	std::cout << "FragTrap: Destructor called." << std::endl;
}