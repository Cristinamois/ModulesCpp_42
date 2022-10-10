#include <iostream>
#include <cstdlib>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
	int random = (std::rand()) % 3;

	if (random == 0)
		return new A;
	if (random == 1)
		return new B;
	else
		return new C;
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p))
		std::cout << "Identified class A." << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Identified class B." << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Identified class C." << std::endl;
	else
		std::cout << "Uh something went wrong, pls try again." << std::endl;
}

void identify(Base &p) {
	try {
		(void) dynamic_cast<A&>(p);
		std::cout << "Identified class A." << std::endl;
	} catch (std::exception &e) {
		(void) e;
		try {
			(void) dynamic_cast<B&>(p);
			std::cout << "Identified class B." << std::endl;
		} catch (std::exception &e1) {
			(void) e1;
			try {
				(void) dynamic_cast<C&>(p);
				std::cout << "Identified class C." << std::endl;
			} catch (std::exception &e2) {
				(void) e2;
				std::cout << "Uh ... Something went wrong, pls try again." << std::endl;
			}
		}
	}
}

int main() {
	std::srand(std::time(NULL));

	Base *randomClass = generate();

	identify(randomClass);
	identify(*randomClass);
}
