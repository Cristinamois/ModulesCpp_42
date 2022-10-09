#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <cstring>
#include "Form.hpp"

class Form;

class Bureaucrat {
public:
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &src);
	virtual ~Bureaucrat();
	const std::string &getName() const;
	const int &getGrade() const;
	void gradeUp();
	void gradeDown();
	void signForm(Form &form);
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
	Bureaucrat &operator=(const Bureaucrat &src);
	const std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif