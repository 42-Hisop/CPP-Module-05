#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private :
		std::string	_target;
		
	public :
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		
		virtual ~RobotomyRequestForm();

		bool execute(const Bureaucrat &bureaucrat) const;

		RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
};

#endif
