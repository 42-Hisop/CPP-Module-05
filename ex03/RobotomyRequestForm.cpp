#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", 72, 45), _target("noname")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

bool RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	int	robotized;

	try
	{
		if (this->checkSignature(executor) == true)
		{
			std::cout << "Brrrrrrrr" << std::endl;
			std::srand(std::time(NULL));
			robotized = rand() % 2;
			if (robotized == 1)
				std::cout << this->_target << " has been robotimized." << std::endl;
			else
				std::cout << "The operation failed" << std::endl;
		}
	}
	catch (const Form::cannotSigned &e)
	{
		std::cerr << e.what() << '\n';
		return (false);
	}
	return (true);
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		this->_target = other._target;
	return (*this);
}
