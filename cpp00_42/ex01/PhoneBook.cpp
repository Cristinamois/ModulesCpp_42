
#include "PhoneBook.hpp"


void	PhoneBook::srchHandle(PhoneBook book, std::string cmd)
{
	int srchNbr = 0;
	for (int i = 0; i < 8; i++)
	{
		book.contact[i].printInfo(book.contact[i], i);
	}
	std::cout << std::endl;
	std::cout << "Enter the index number of the contact you want to focus on : " << std::endl;
	std::cin >> cmd;
	if (isdigit(cmd[0]))
		srchNbr = ft_stoi(cmd) - 1;
	else
		std::cout << "This was not a digit. Try again. Or maybe you wrote a negative number which is not correct." << std::endl;
	if ((cmd.length() > 1) || cmd == "0" || srchNbr < 0)
		std::cout << std::endl<< std::endl << "Please enter a number from 1 - 8." << std::endl;
	if ((srchNbr >= 1 && srchNbr < 9) || (cmd == "1"))
		book.PhoneBook::contact[srchNbr].printFromIndex(book.contact[srchNbr]);
}

int	PhoneBook::exitHandle(void)
{
	std::cout << std::endl << std::endl;
	std::cout << "See you later :)" << std::endl;
	return (0);
}
