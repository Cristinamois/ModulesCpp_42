#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <cmath>


class ClapTrap {
public:
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap &src);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	virtual ~ClapTrap();
	ClapTrap &operator=(const ClapTrap &src);

protected:
	ClapTrap();
	std::string _name;
	int _hitP;
	int _energyP;
	int _attackD;
};


#endif
