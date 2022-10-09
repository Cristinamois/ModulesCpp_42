#include "Form.hpp"


Form::Form(const std::string &name, int signG, int execG): _name(name), _signed(false), _signG(signG), _execG(execG) 
{
	std::cout << "Form Constructor called" << std::endl;
	if (signG < 1)
		throw GradeTooLowException();
	if (signG > 150)
		throw GradeTooLowException();
	if (execG < 1)
		throw GradeTooLowException();
	if (execG > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &src): _name(src._name), _signG(src._signG), _execG(src._execG) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Form &Form::operator=(const Form &src) 
{
	std::cout << "Assign op called" << std::endl;
	this->_signed = src._signed;
	return *this;
}

Form::~Form() 
{
	std::cout << "Form Destructor called" << std::endl;
}

void Form::beSigned(Bureaucrat const &bureaucrat) 
{
	if (bureaucrat.getGrade() > this->_signG)
		throw GradeTooLowException();
	this->_signed = true;
}

const std::string &Form::getName() const 
{
	return this->_name;
}

bool Form::isSigned() const {
	return this->_signed;
}

int Form::getSignGrade() const {
	return this->_signG;
}

int Form::getExecGrade() const {
	return this->_execG;
}

void Form::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (!this->isSigned())
		throw FormNotSignedException();
	std::cout << this->_name << " has been executed" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "name: " << form.getName() << ", signed: " << form.isSigned()
	   << ", signGrade: " << form.getSignGrade() << ", execGrade: " << form.getExecGrade();
	return os;
}
