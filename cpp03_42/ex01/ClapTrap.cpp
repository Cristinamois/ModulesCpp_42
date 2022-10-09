#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"), _hitP(10), _energyP(10), _attackD(0) {
	std::cout << "claptrap : " << " Default contructor called!" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitP(10), _energyP(10), _attackD(0) {
	std::cout << "claptrap: " << this->_name << " constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	std::cout << "claptrap : " << "Copy constructor called!" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap() {
	std::cout << "claptrap : " << this->_name << " destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
	this->_hitP = src._hitP;
	this->_energyP = src._energyP;
	this->_attackD = src._attackD;
	this->_name = src._name;
	return *this;
}

void ClapTrap::attack(const std::string &target) {
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

	std::cout  << this->_name << " attacked "<< target << " causing " << this->_attackD << " damage." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (!this->_hitP)
	{
		std::cout << this->_name << " is already dead. Sry for your loss" << std::endl;
		return;
	}

	amount = std::min(amount, (unsigned int) this->_hitP);
	this->_hitP -= amount;

	std::cout << this->_name << " lost " << amount << " hitP" << std::endl;
	if (!_hitP)
		std::cout << this->_name << " died" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!this->_hitP)
	{
		std::cout << this->_name << " tried to repair but is dead" << std::endl;
		return;
	}
	if (!this->_energyP)
	{
		std::cout << this->_name << " tried to repair but no energy left" << std::endl;
		return;
	}

	amount = std::min(amount, (unsigned int) this->_energyP);

	this->_hitP += amount;
	this->_energyP -= amount;

	std::cout << this->_name << " repaired for " << amount << " hitP" << std::endl;
}

