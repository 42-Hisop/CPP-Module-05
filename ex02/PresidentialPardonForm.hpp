#ifndef PRESIDENTIALPARDONFORM_HPP 
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm :public Form
{
	private :
		std::string	_target;
	public :
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		
		virtual ~PresidentialPardonForm();

		bool execute(const Bureaucrat &bureaucrat) const;
		
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
};

#endif
