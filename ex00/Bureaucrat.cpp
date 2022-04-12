#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		else if (150 < grade)
			throw GradeTooLowException();
		else
			_grade = grade;
	}

	catch(GradeTooHighException &e)
	{
		std::cerr << e.what() << '\n';
	}

	catch(GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName())
{
	*this = src;
	return ;
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

const std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrGrade(void)
{
	try
	{
		_grade--;
		if (_grade < 1)
			throw GradeTooHighException();
		else if (150 < _grade)
			throw GradeTooLowException();
	}

	catch(GradeTooHighException &e)
	{
		std::cerr << e.what() << '\n';
	}

	catch(GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	return ;
}

void	Bureaucrat::decrGrade(void)
{
	try
	{
		_grade++;
		if (_grade < 1)
			throw GradeTooHighException();
		else if (150 < _grade)
			throw GradeTooLowException();
	}

	catch(GradeTooHighException &e)
	{
		std::cerr << e.what() << '\n';
	}

	catch(GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	return ;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other.getGrade();
	return (*this);
}

std::ostream	&operator<<(std::ostream &flux, const Bureaucrat &src)
{
	flux << src.getName() << ", Bureaucrat grade " << src.getGrade() << std::endl;
	return (flux);
}
