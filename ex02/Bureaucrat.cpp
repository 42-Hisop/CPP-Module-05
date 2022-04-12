#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("noname"), _grade(150)
{
	std::cout << "make new Bureaucrat, name : " << _name << " grade : " << 
				_grade << std::endl;
	return ;
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
		{
			_grade = grade;
			std::cout << "make new Bureaucrat, name : " << _name << " grade : " << 
				grade << std::endl;
		}
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

void	Bureaucrat::signForm(Form &form) const
{
	try
	{
		if (form.beSigned(*this) == true)
			std::cout << this->getName() << " signed " << form.getName() << std::endl;
		else
			throw GradeTooLowException();
	}
	catch (GradeTooLowException &e)
	{
		std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << 
			e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(Form &form) const
{
	try
	{
		if (form.execute(*this) == true)
			std::cout << this->getName() << " execute " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
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
