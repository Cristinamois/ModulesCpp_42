#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include "Form.hpp"

class RobotomyRequestForm: public Form 
{
	private:
		RobotomyRequestForm &operator=(RobotomyRequestForm &src);

		const std::string _target;
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		~RobotomyRequestForm();
		void execute(const Bureaucrat &executor) const;
};

#endif
