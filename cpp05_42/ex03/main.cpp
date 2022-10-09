#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	{
		Intern bob;
		PresidentialPardonForm *Presidou;
		RobotomyRequestForm *T3po;
		ShrubberyCreationForm *Pnl;
		Form *check;

		Presidou = (PresidentialPardonForm*) bob.makeForm("Presidential Pardon", "Macrondemission");
		T3po = (RobotomyRequestForm*)bob.makeForm("Robotomy Request", "3301");
		Pnl = (ShrubberyCreationForm*)bob.makeForm("Shrubbery Creation", "paper");
		check = bob.makeForm("a form","something");
		std::cout << *Presidou << std::endl << *T3po << std::endl << *Pnl << std::endl;
		delete Presidou;
		delete T3po;
		delete Pnl;
		delete check;
	}
	return (0);
}
