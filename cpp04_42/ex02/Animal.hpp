#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"

class Animal 
{
	protected:
		std::string _type;
	public:
		virtual Animal 		&operator=(const Animal &src);
		virtual 			~Animal();
		virtual void 				makeSound() const = 0;
		const std::string 	&getType() const;
		virtual Brain		*getBrain( void ) const = 0;

};


#endif
