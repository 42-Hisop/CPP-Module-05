#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat	random;
	Bureaucrat	A("A", 120);
	Bureaucrat	B("B", 42);
	Bureaucrat	C("C", 3);
	Bureaucrat	D("D", 67);
	std::cout << std::endl;
	
	Form	*shForm = new ShrubberyCreationForm("hi");
	Form	*roForm = new RobotomyRequestForm("hello");
	Form	*prForm = new PresidentialPardonForm("asdf");

	std::cout << *shForm << std::endl;
	std::cout << *roForm << std::endl;
	std::cout << *prForm << std::endl;
	
	std::cout << std::endl;

	A.signForm(*shForm);
	shForm->beSigned(A);
	roForm->beSigned(B);
	prForm->beSigned(C);
	
	A.executeForm(*shForm);
	B.executeForm(*roForm);
	C.executeForm(*prForm);

	delete	shForm;
	delete	roForm;
	delete	prForm;
	return (0);
}
