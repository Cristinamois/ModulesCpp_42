#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <cstring>

class Bureaucrat
{
	private:
		std::string const  _name;
		unsigned int _grade;
		Bureaucrat &operator=(const Bureaucrat &lhs);
	public:
		Bureaucrat();
		virtual ~Bureaucrat();
		Bureaucrat(const Bureaucrat &rep);
		Bureaucrat(const std::string name, unsigned int grade);
		class GradeTooHighException: public std::exception 
		{
			public:
				virtual const char* what() const throw() 
				{
					return ("grade is too high");
				}
		};
		class GradeTooLowException: public std::exception 
		{
			public:
			virtual const char* what() const throw() 
			{
				return ("grade is too low");
			}
		};
		const std::string	&getName() const;
		const unsigned int 	&getGrade() const;
		void	elevation();
		void	diminution();

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif