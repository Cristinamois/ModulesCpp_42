#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"

class Animal {
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const Animal &src);
		Animal &operator=(const Animal &src);
		virtual ~Animal();
		void makeSound() const;
		const std::string &getType() const;
		virtual Brain		*getBrain( void ) const = 0;
};


#endif
