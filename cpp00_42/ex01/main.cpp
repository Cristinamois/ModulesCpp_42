# include "main.hpp"
# include "ContactInfo.hpp"
# include "PhoneBook.hpp"

void	talking()
{
	std::cout << std::endl << std::endl;
	std::cout << "Welcome." << std::endl;
	std::cout << "You can enter 3 different commands:" << std::endl;
	std::cout << "ADD: to add a new contact." << std::endl;
	std::cout << "SEARCH: to search into the Phonebook and see all 8 contacts." << std::endl;
	std::cout << "EXIT: to exit the programm" << std::endl;
	std::cout << std::endl << std::endl;	
}

int	ft_stoi(std::string str)
{
	int i = 0;
	int ret = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			ret = ret * 10 + str[i++] - '0';

	}
	return (ret);
}

int main()
{
	PhoneBook book;
	int index;
	std::string cmd;
	// int SrchNbr = 0;
	index = 0;

	while (1)
	{
		talking();
		std::cin >> cmd;
		if (std::cin.eof()==1) 
        {
            std::cin.clear();
			std::cout << "Invalid command." << std::endl;  
            return (0);
        }
		if (cmd == SRCHCMD)
			book.srchHandle(book, cmd);
		else if (cmd == ADDCMD)
		{
			if (index == 8)
				index = 0;
			book.PhoneBook::contact[index].getInfo(book.contact, index);
			index++;
		}
		else if (cmd == EXITCMD)
			return (book.exitHandle());
		else
			std::cout << INVALID_CMD << std::endl;
	}

}