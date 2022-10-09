#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	meta->makeSound();
	cat->makeSound();
	dog->makeSound();

	delete meta;
	delete cat;
	delete dog;
	
	std::cout << std::endl;

	const WrongAnimal* metaWrong = new WrongAnimal();
	const WrongAnimal* catWrong = new WrongCat();
	// const WrongCat*		test = new WrongCat();

	std::cout << catWrong->getType() << std::endl;
	// std::cout << test->getType() << std::endl;

	metaWrong->makeSound();
	catWrong->makeSound();
	// test->makeSound();

	delete metaWrong;
	delete catWrong;
	// delete test;
}
