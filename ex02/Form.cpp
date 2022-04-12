#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("noname"), _signedGrade(150), _execGrade(150), _signed(false)
{
	return ;
}

Form::Form(std::string name, int signedGrade, int execGrade) : _name(name), _signedGrade(signedGrade), _execGrade(execGrade), _signed(false)
{
	try
	{
		checkGrade(signedGrade, execGrade);
	}
	catch(GradeTooHighException &e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}
	return ;
}

Form::Form(const Form &src) : _name("noname"), _signedGrade(src._signedGrade), _execGrade(src._execGrade)
{
	*this = src;
}

Form::~Form()
{
	return ;
}

const std::string	Form::getName(void) const
{
	return _name;
}

int	Form::getSignedGrade(void) const
{
	return _signedGrade;
}

int Form::getExecGrade(void) const
{
	return _execGrade;
}

bool	Form::getSigned(void) const
{
	return _signed;
}

bool	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() >= _signedGrade)
		return (false);
	else
		_signed = true;
	return (true);
}

void	Form::checkGrade(int signedGrade, int execGrade)
{
	if (signedGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signedGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

bool	Form::checkSignature(const Bureaucrat &executor) const
{
	if (this->_signed == false || executor.getGrade() > this->_execGrade)
		throw cannotSigned();
	return (true);
}

Form	&Form::operator=(const Form &other)
{
	_signed = other._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &flux, const Form &form)
{
	flux << "Form " << form.getName() << std::endl;
	flux << "Signed grade : " << form.getSignedGrade() << std::endl;
	flux << "Exec grade : " << form.getExecGrade() << std::endl;
	return (flux);
}
