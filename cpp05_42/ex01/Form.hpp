#ifndef FORM_HPP
# define FORM_HPP



#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
	Form(const std::string &name, int signGrade, int execGrade);
	Form(const Form &src);
	virtual ~Form();

	void beSigned(Bureaucrat &bureaucrat);

	const std::string &getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	class GradeTooHighException: public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("grade is too high");
		}
	};
	class GradeTooLowException: public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("grade is too low");
		}
	};
private:
	Form &operator=(const Form &src);

	std::string const _name;
	bool _signed;
	const int _sGrade;
	const int execGrade;
};

std::ostream &operator<<(std::ostream &os, const Form &Form);

#endif