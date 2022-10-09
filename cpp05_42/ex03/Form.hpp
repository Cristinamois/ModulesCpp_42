#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"


class Bureaucrat;

class Form {
	private:
		Form &operator=(const Form &form);

		std::string _name;
		bool _signed;
		const int _signG;
		const int _execG;
	public:
		Form(const std::string &name, int signG, int execG);
		Form(const Form &src);
		virtual ~Form();

		void beSigned(Bureaucrat const &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const;

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
		class FormNotSignedException: public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("form is not signed");
			}
		};
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
