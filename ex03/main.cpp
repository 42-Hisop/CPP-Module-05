#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
	Bureaucrat	random("random", 1);

	Form	*shForm;
	Form	*roForm;
	Form	*prForm;
	Form	*bad;

	shForm = intern.makeForm("shrubbery creation", "hi");
	roForm = intern.makeForm("robotomy request", "hello");
	prForm = intern.makeForm("presidential pardon", "asdf");
	bad = intern.makeForm("dd", "noname");

	std::cout << std::endl;
	
	std::cout << *shForm << std::endl;
	std::cout << *roForm << std::endl;
	std::cout << *prForm << std::endl;
	
	std::cout << std::endl;

	shForm->beSigned(random);
	roForm->beSigned(random);
	prForm->beSigned(random);

	random.executeForm(*shForm);
	random.executeForm(*roForm);
	random.executeForm(*prForm);

	delete	shForm;
	delete	roForm;
	delete	prForm;
	return (0);
}
