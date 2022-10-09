#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>
#include <iostream>

#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		Bureaucrat &operator=(const Bureaucrat &lhs);
		const std::string _name;
		int _grade;
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		virtual ~Bureaucrat();
		const std::string &getName() const;
		const int &getGrade() const;
		void gradeUp();
		void gradeDown();
		void signForm(Form &form);
		void executeForm(const Form &form);
		
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
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
