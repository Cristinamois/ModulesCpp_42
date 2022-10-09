#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	std::cout <<this->_name  << " Constructor called" << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src._name) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)  {
	std::cout << "Assignement operator called" << std::endl;
	this->_grade = src._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << this->_name << " Destructor called" << std::endl;
}

const std::string &Bureaucrat::getName() const {
	return this->_name;
}

const int &Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::gradeUp() {
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	else
		this->_grade -= 1;
}

void Bureaucrat::gradeDown() {
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	else
		this->_grade += 1;
}

void Bureaucrat::signForm(Form &Form) {
	try {
		Form.beSigned(*this);

		std::cout << this->_name + " signed form " + Form.getName() << std::endl;
	} catch (Form::GradeTooLowException &e) {
		std::cout << this->_name + " could not sign form " + Form.getName() + " because " + e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}