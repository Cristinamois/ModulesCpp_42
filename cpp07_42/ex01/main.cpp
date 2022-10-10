#include "iter.hpp"

void	function(int &i)
{
	i -= 42;
}

void	addInStr(std::string &str)
{
	str.append(" est fatigue.");
}

int main(void)
{
	std::cout << "int  test : " << std::endl;
	int tab[] = {42, 43, 44, 45};
	for (int i = 0; i < 4; i++)
		std::cout << " tab[" << i << "]: " << tab[i] << std::endl;
	iter(tab, 4, &function);
	for (int i = 0; i < 4; i ++)
		std::cout << " tab[" << i << "]: " << tab[i] << std::endl;
	
	std::cout << "str test : " << std::endl;
	std::string tabStr[] = {"Lucifer", "Cristina", "quarandaxxxx ou koi", "foo"};
	for (int i = 0; i < 4; i++)
		std::cout << " tabStr[" << i << "]: " << tabStr[i] << std::endl;
	iter(tabStr, 4, addInStr);
	for (int i = 0; i < 4; i++)
	std::cout << " tabStr[" << i << "]: " << tabStr[i] << std::endl;


}