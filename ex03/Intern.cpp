#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

Intern::Intern(void)
{
	_forms[0] = "shrubbery creation";
	_forms[1] = "robotomy request";
	_forms[2] = "presidential pardon";
	return ;
}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern::~Intern(void)
{
	return ;
}

Form *Intern::makeForm(const std::string name, const std::string target)
{
	int i = 0;
	
	while (i < 3)
	{
		if (_forms[i] == name)
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			std::cout << "Intern Create " << _forms[i] << std::endl;
			return new ShrubberyCreationForm(target);
		case 1:
			std::cout << "Intern Create " << _forms[i] << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "Intern Create " << _forms[i] << std::endl;
			return new PresidentialPardonForm(target);
		default :
			std::cout << "wrong input" << std::endl;
			break;	
	}
	return (NULL);
}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}
