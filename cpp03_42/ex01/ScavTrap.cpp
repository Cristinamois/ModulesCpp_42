#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout<< "scavtrap: " << " Default constructor called!" << std::endl;
	this->_name = "ScavTrap";
	this->_hitP = 100;
	this->_energyP = 50;
	this->_attackD = 20;
}

void	ScavTrap::attack(const std::string &target)
{
	if (!this->_hitP)
	{
		std::cout << this->_name << " tried to attack but dead." << std::endl;
		return;
	}
	if (!this->_energyP)
	{
		std::cout<< this->_name << " tried to attack : No energy left." << std::endl;
		return;
	}

	std::cout  << this->_name << " attacked "<< target << ", as an individual scavy,  causing " << this->_attackD << " damage." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	std::cout<< "ScavTrap: " << this->_name << " constructor called and is AN INDIVIDUAL SCAVY" << std::endl;
	this->_hitP = 100;
	this->_energyP = 50;
	this->_attackD = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap() {
	std::cout<< "scavTrap : " << this->_name << " copy constructor called!(still individual)" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap() {
	std::cout<< "scavtrap: " <<  this->_name << " the (rrrrr) individual scavy destructor called" << std::endl;
}

void ScavTrap::guardGate() {
	if (!this->_hitP)
	{
		std::cout<< this->_name << " tried to enter guard keeper mode but is dead" << std::endl;
		return;
	}
	std::cout<< this->_name << " is in Guate Keeper mode." << std::endl;
}
