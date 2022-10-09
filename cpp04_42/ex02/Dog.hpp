#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal 
{
	private:
		Brain *_brain;
	public:
		Dog();
		Dog(const Dog &src);
		~Dog();
		Dog &operator=( Dog const &src );
		Animal &operator=( Animal const &src );
		void makeSound() const;
		virtual Brain *getBrain() const;
};


#endif
