#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm: public Form {
public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	~ShrubberyCreationForm();

	void execute(const Bureaucrat &executor) const;
	class OutputFileException: public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("could not open output file");
		}
	};
private:
	ShrubberyCreationForm &operator=(ShrubberyCreationForm &lhs);

	const std::string _target;
};

#endif
