#include "Harl.hpp"

void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"
            << " ketchup burger. I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didnt put"
           <<  " enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. Ive been coming for " << " years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "his is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{

    
    std::string complains[] = {"1", "2", "3", "4"};
	void (Harl:: *complainLvl[]) (void) = {
		complainLvl[0] = &Harl::debug,
		complainLvl[1] = &Harl::info,
		complainLvl[2] = &Harl::warning,
		complainLvl[3] = &Harl::error
	};
	for (int i = 0; i < 4; i++)
		if (complains[i] == level)
		{
			(this->*complainLvl[i])();
			return ;
		}
}
