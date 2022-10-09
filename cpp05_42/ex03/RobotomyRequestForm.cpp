#include "Form.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): Form("Robotomy Request Form", 72, 45), _target(target) 
{
	std::cout << "Robotomy request Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): Form(src.getName(), src.getSignGrade(), src.getExecGrade()), _target(src._target) 
{
	std::cout << "Robotomy request Copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() 
{
	std::cout << "Robotomy request Destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &src) 
{
	std::cout << "Robotomy request Assgin op called" << std::endl;
	(void) src;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (!this->isSigned())
		throw FormNotSignedException();
	std::cout << "* BVvvvvvvzzzzzziiiouuuu *" << std::endl;
	if (std::rand() % 2)
		std::cout << "Operation succeeded on " << this->_target << std::endl;
	else
		std::cout << "Operation did not succeed on " << this->_target << std::endl; 
}
