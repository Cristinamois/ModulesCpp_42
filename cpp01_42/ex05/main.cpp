

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;
	if (ac > 1)
		harl.complain(av[1]);
	else
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}