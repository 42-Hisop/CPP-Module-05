#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5), _target("noname")
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

bool PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	try
	{
		if (this->checkSignature(executor) == true)
			std::cout << this->_target << " was excused by Zafod Beeblebrox." << std::endl;
	}
	catch (const Form::cannotSigned &e)
	{
		std::cerr << e.what() << '\n';
		return (false);
	}
	return (true);
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		this->_target = other._target;
	return (*this);
}
