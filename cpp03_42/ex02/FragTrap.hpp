#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected:
		FragTrap();
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &clap);
		~FragTrap();
		void highFivesGuys(void);
};

# endif