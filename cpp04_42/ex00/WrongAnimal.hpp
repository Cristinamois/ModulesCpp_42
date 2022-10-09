#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal 
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &src);
		WrongAnimal &operator=(const WrongAnimal &rep);
		~WrongAnimal();
		void makeSound() const;
		const std::string &getType() const;
	protected:
		std::string _type;
};


#endif
