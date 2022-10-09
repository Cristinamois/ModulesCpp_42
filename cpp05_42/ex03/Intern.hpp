#ifndef INTERN_HPP
#define INTERN_HPP


# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		static Form * _createPresidentialPardonForm(std::string const & target);
		static Form * _createRobotomyRequestForm(std::string const & target);
		static Form * _createShrubberyCreationForm(std::string const & target);
	public:
		Intern();
		Intern(Intern const & src);
		virtual ~Intern();
		Intern & operator=(Intern const &);
		Form * makeForm(std::string const & _formName, std::string const & _targetName);
};


#endif