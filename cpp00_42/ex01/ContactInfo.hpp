
#ifndef CONTACTINFO_HPP
# define CONTACTINFO_HPP

#include "main.hpp"

class ContactInfo
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
	public:
		int	index;
		void	getInfo(ContactInfo *contact, int i);
		void	printFromIndex(ContactInfo contact);
		void	printInfo(ContactInfo contact, int i);
		int		CheckLengthAndCutIfNeeded(ContactInfo *contact);

};

# endif