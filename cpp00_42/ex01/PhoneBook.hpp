
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"

class PhoneBook
{
	public:
		ContactInfo contact[8];
		void	srchHandle(PhoneBook book, std::string cmd);
		int		exitHandle();
};


#endif