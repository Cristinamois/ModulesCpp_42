#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
private:
	Brain *_brain;
public:
	Cat();
	Cat(const Cat &src);
	~Cat();
	Cat &operator=( Cat const &src );
	Animal &operator=( Animal const &src );
	void makeSound() const;
	Brain *getBrain() const;
};


#endif
