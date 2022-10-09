#include "Cat.hpp"
#include "Dog.hpp"

#define nbr_animals 8

int	main(void )
{
	Animal	*animals[nbr_animals];
	Brain	*brain;
	for (int i = 0; i < nbr_animals; i++)
	{
		if (i < nbr_animals / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << animals[i]->getType() << std::endl;
	}
	brain = animals[6]->getBrain();
	brain->ideas[0] = "Eat";
	brain->ideas[1] = "Sleep";
	brain->ideas[2] = "Watch tv";
	brain->ideas[3] = "sleep more";
	std::cout << animals[6]->getBrain()->ideas[2] << std::endl;
	
	*(animals[5]) = *(animals[7]);
	std::cout << animals[5]->getBrain()->ideas[2] << std::endl;
	for (int i = 0; i < nbr_animals; i++)
		delete animals[i];
}
