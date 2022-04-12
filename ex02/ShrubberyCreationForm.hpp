#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private :
		std::string	_target;
	public :
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);

		virtual ~ShrubberyCreationForm();

		bool execute(const Bureaucrat &bureaucrat) const;

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
};

#endif
