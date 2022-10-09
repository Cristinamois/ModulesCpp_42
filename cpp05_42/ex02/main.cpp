#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ctime>

int main(void) {
	
	Form *form = NULL;
	Bureaucrat Cristina("Cristina", 1);
	Bureaucrat Lucifer("Lucifer", 40);
	Bureaucrat foo("foo", 14);

	try {
		form = new PresidentialPardonForm("Macron");
		Cristina.executeForm(*form);
		delete form;
		form = NULL;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		form = new PresidentialPardonForm("Macron");
		Cristina.signForm(*form);
		Cristina.executeForm(*form);
		delete form;
		form = NULL;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		form = new RobotomyRequestForm("c3po");
		Cristina.signForm(*form);
		Lucifer.executeForm(*form);
		Lucifer.executeForm(*form);
		delete form;
		form = NULL;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		form = new ShrubberyCreationForm("tree");
		Cristina.signForm(*form);
		Lucifer.executeForm(*form);
		foo.executeForm(*form);
		delete form;
		form = NULL;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
}

	return 0;
}
