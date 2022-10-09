#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): Form("Shruberry Creation Form", 145, 137), _target(target) 
{
	std::cout << "Shrubbery creation Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): Form(src.getName(), src.getSignGrade(), src.getExecGrade()), _target(src._target) 
{
	std::cout << "Shruberry creation cpy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
	std::cout << std::endl << "Shrubbery creation Destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &src) 
{
	std::cout << "Shrubbery creation Assign op called" << std::endl;
	(void)src;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (!this->isSigned())
		throw FormNotSignedException();
	std::ofstream outfile((this->_target + "_shrubbery").c_str());				//https://stackoverflow.com/questions/478075/creating-files-in-c
	if (!outfile.is_open())
		throw OutputFileException();

outfile<< "	       ,@@@@@@@" << std::endl;
outfile<< "       ,,,.   ,@@@@@@/@@,  .oo****o." << std::endl;
outfile<< "    ,&%%&%&&%,@@@@@/@@@@@@,*********o" << std::endl;
outfile<< "   ,%&&&&%&&%,@@@@@@@/@@@************'" << std::endl;
outfile<< "   %&&%&%&/%&&%@@@@@/ /@@@************'" << std::endl;
outfile<< "   %&&%/ %&%%&&@@@ V /@@' `***** `/**'" << std::endl;
outfile<< "   `&%  ` /%&'    |.|        \\ '|**'" << std::endl;
outfile<< "       |o|        | |         | |" << std::endl;
outfile<< "       |.|        | |         | |" << std::endl;
outfile<< " \\/ ._|/_/__/  ,| //__\\/.  |_//__/_" << std::endl;


	outfile.close();
	std::cout << "Drew a tree in " << this->_target << "_shrubbery" << std::endl;
}
