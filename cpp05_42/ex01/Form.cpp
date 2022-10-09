#include "Form.hpp"

Form::Form(const std::string &name, int signGrade, int execGrade): _name(name), _signed(false), _sGrade(signGrade), execGrade(execGrade) {
	std::cout << this->_name << " Constructor called" << std::endl;
	if (signGrade < 1)
		throw GradeTooLowException();
	if (signGrade > 150)
		throw GradeTooLowException();
	if (execGrade < 1)
		throw GradeTooLowException();
	if (execGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &src): _name(src._name), _sGrade(src._sGrade), execGrade(src.execGrade) {
	std::cout << "Copy constructor called" << std::endl;;
	*this = src;
}

Form &Form::operator=(const Form &src) {
	std::cout << "Assignement operator called" << std::endl;
	this->_signed = src._signed;
	return *this;
}

Form::~Form() {
	std::cout << this->_name << " Destructor called" << std::endl;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->_sGrade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

const std::string &Form::getName() const {
	return this->_name;
}

bool Form::isSigned() const {
	return this->_signed;
}

int Form::getSignGrade() const {
	return this->_sGrade;
}

int Form::getExecGrade() const {
	return this->execGrade;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "name: " << form.getName() << ", signed: " << form.isSigned()
	   << ", signGrade: " << form.getSignGrade() << ", execGrade: " << form.getExecGrade();
	return os;
}

// Form &Form::operator=(const Form &lhs) {
// 	std::cout << "Assignement operator called" << std::endl;
// 	this->_signed = lhs._signed;
// 	return *this;
// }

// Form &Form::operator=(const Form &lhs) 
// {
// 	dprintln("Assignement operator called");
// 	this->_signed = lhs._signed;
// 	return *this;
// }
