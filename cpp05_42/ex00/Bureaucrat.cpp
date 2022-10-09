#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name(name)
{
	std::cout << "Constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooLowException();
	else if (grade > 150)
		throw GradeTooHighException();
	else
		this->_grade = grade;

}

void	Bureaucrat::elevation()
{
	if ((this->_grade - 1) < 1)
		throw GradeTooHighException();
	else
		this->_grade -= 1;
}

void	Bureaucrat::diminution()
{
	if ((this->_grade + 1) > 150)
		throw GradeTooLowException();
	else
		this->_grade += 1;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src._name), _grade(src._grade)
{
	std::cout << this->_name << "Cpy constructor called" << std::endl;;
}

const std::string	&Bureaucrat::getName() const
{
	// std::cout << "name : " <<  this->_name << std::endl;
	return (this->_name);
}

const unsigned int &Bureaucrat::getGrade() const
{
	return (this->_grade);
}


Bureaucrat::~Bureaucrat()
{
	std::cout << "Default destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &lhs)  
{
	std::cout << "Assignement operator called" << std::endl;
	this->_grade = lhs._grade;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) 
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}