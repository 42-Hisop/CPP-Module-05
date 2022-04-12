#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"

class Form;

class Intern
{
	private :
		std::string _forms[3];

	public :
		Intern(void);
		Intern(const Intern &src);

		~Intern();

		Form *makeForm(const std::string name, const std::string target);
		
		Intern &operator=(const Intern &other);
};

#endif
