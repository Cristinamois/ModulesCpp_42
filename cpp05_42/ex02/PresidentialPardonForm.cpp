#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(const std::string &target): Form("Presidential Pardon Form", 25, 5), _target(target) 
{
	std::cout << "Presidential pardon Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): Form(src.getName(), src.getSignGrade(), src.getExecGrade()), _target(src._target) 
{
	std::cout << "Presidential pardon Copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() 
{
	std::cout << "Presidential pardon Destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &src) 
{
	std::cout << "Presidential pardonAssign op called" << std::endl; 
	(void) src;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (!this->isSigned())
		throw FormNotSignedException();
	std::cout << this->_target << " has been forgiven by Zaphod Beeblebrox" << std::endl;
}
