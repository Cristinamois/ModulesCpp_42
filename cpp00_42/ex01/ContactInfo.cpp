#include "ContactInfo.hpp"


void	ContactInfo::getInfo(ContactInfo *contact, int i)
{
	contact[i].index = i;
	std::cout << "You're adding a new contact." << std::endl;

	std::cout << "Please write the First Name :" << std::endl;
	std::cin >> this->_firstName;
	std::cout << "Now the Last Name :" << std::endl;
	std::cin >> this->_lastName;
	std::cout << "Nicknames are cool, is there any you can give tothis contact ?:" << std::endl;
	std::cin >> this->_nickName;
	std::cout << "Now a phone number. Everything is kept secret, don't worry :)" << std::endl;
	std::cin >> this->_phoneNumber;
	std::cout << "Ok last one, write down the darkest secret about them... ihihi" << std::endl;
	std::cin >> this->_darkestSecret;

	std::cout << "Thank you, this contact is in the PhoneBook now." << std::endl;
}

int	IsHigher(std::string str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (i > 9)
		return (1);
	return (0);
}

void	NeedCut(std::string *firstname, std::string *lastname, std::string *nickname)
{
	// std::cout << "Needs cut yes" << std::endl;
	std::string firstcpy;
	std::string lastcpy;
	std::string nickcpy;
	if (IsHigher((*firstname)) == 1)
	{
		firstcpy = (*firstname).substr(0,10);
		firstcpy[9] = '.';
		// std::cout << "firstcpy here : " << firstcpy << std::endl;
		(*firstname) = firstcpy;
	}
	if (IsHigher((*lastname)) == 1)
	{
		lastcpy = (*lastname).substr(0,10);
		lastcpy[9] = '.';
		(*lastname) = lastcpy;
	}
	if (IsHigher((*nickname)) == 1)
	{
		nickcpy = (*nickname).substr(0,10);
		nickcpy[9] = '.';
		(*nickname) = nickcpy;
	}
}

int		ContactInfo::CheckLengthAndCutIfNeeded(ContactInfo *contact)
{
	// std::cout << "goes here" << std::endl;
	(void)*contact;
	if (IsHigher(this->_firstName) == 1 || IsHigher(this->_lastName) == 1
		|| IsHigher(this->_nickName) == 1)
		NeedCut(&this->_firstName, &this->_lastName, &this->_nickName);
	return (1);
}

int length(std::string str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	PutWhiteSpaceFromLength(std::string first_name)
{
	int len = length(first_name);
	int white_space = 10 - len;
	for (int i = 0; i < white_space; i++)
		std::cout << " ";
}

void	ContactInfo::printInfo(ContactInfo contact, int i)
{
	int LengthOk = 0;
	int index = i + 1;
	if (i == 0)
		std::cout << "    Index|first name| last name|  nickname|" << std::endl;
	if (CheckLengthAndCutIfNeeded(&contact) == 1)
		LengthOk = 1;
	
	std::cout << "        " << index << "|";
	PutWhiteSpaceFromLength(this->_firstName);
	std::cout << this->_firstName;
	std::cout << "|";
	PutWhiteSpaceFromLength(this->_lastName);
	std::cout << this->_lastName;
	std::cout << "|";
	PutWhiteSpaceFromLength(this->_nickName);
	std::cout << this->_nickName;
	std::cout << "|" << std::endl;

}

void	ContactInfo::printFromIndex(ContactInfo contact)
{
	(void)contact;
	std::cout << std::endl << std::endl;
	std::cout << "Here are the information you can acces of the contact you're looking for." << std::endl;
	std::cout << "First name : " << this->_firstName << std::endl;
	std::cout << "Last name : " << this->_lastName << std::endl;
	std::cout << "Nickname : " << this->_nickName << std::endl;
}
