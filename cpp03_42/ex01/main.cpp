#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{

	ClapTrap clap("cris");
	ScavTrap clop("cross");
	ScavTrap scav;

	scav.attack("coco");
	clap.attack("life");
	clap.takeDamage(50);
	clap.beRepaired(50);
	clop.takeDamage(5);
	clop.beRepaired(20);
	clop.takeDamage(20);
	clop.takeDamage(20);
	scav.guardGate();
	clop.takeDamage(200);
	scav.guardGate();
	scav.attack("lucifer");
	clop.attack("sisilamiff");

}