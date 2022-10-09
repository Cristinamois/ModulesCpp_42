#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm: public Form 
{
	private:
		PresidentialPardonForm &operator=(PresidentialPardonForm &src);
		const std::string _target;
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		~PresidentialPardonForm();
		void execute(const Bureaucrat &executor) const;
};

#endif
