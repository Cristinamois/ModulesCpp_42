#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const & src)
{
	(void)src;
}

Intern::~Intern()
{
}

Intern & Intern::operator=(Intern const &)
{
	return (*this);
}

Form * Intern::makeForm(std::string const & formName, std::string const & targetName)
{
	std::size_t	const nbForms = 3;
	std::string const formNames[nbForms] = {"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};
	Form * (*formDB[nbForms])(std::string const &) =
		{&Intern::_createPresidentialPardonForm, &Intern::_createRobotomyRequestForm, &Intern::_createShrubberyCreationForm};

	for (std::size_t i = 0; i < nbForms; i++)
	{
		// std::cout << formName << std::endl;
		if (formNames[i] == formName)
		{
			// std::cout << "goes here" << std::endl;
			std::cout << "Intern creates '" << formName << "'." << std::endl;
			return (formDB[i](targetName));
		}
	}
	std::cout << "Intern can't create '" << formName << "' Because this form does not exist. Try again." << std::endl;
	return (NULL);
}

Form * Intern::_createPresidentialPardonForm(std::string const & target)
{
	return (new PresidentialPardonForm(target));
}

Form * Intern::_createRobotomyRequestForm(std::string const & target)
{
	return (new RobotomyRequestForm(target));
}

Form * Intern::_createShrubberyCreationForm(std::string const & target)
{
	return (new ShrubberyCreationForm(target));
}