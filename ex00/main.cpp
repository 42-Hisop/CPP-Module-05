#include "Bureaucrat.hpp"

int main()
{
	std::cout << "CREATE BUREAUCRAT" << std::endl;

	Bureaucrat BureaucratA("Bob", 1);
	Bureaucrat BureaucratB("John", 150);
	Bureaucrat BureaucratC("Zak", 0);
	Bureaucrat BureaucratD("Max", 151);
	std::cout << std::endl;

	std::cout << "INCREMENTATION AND DECREMENTATION - exception"<< std::endl;
	BureaucratA.incrGrade();	
	std::cout << BureaucratA.getGrade() << std::endl; 
	BureaucratB.decrGrade();
	std::cout << BureaucratB.getGrade() << std::endl; 
	std::cout << std::endl;

	std::cout << "INCREMENTATION AND DECREMENTATION - valid" << std::endl;
	BureaucratA.decrGrade(); 
	std::cout << BureaucratA.getGrade() << std::endl; 
	BureaucratB.incrGrade();
	std::cout << BureaucratB.getGrade() << std::endl;
	std::cout << std::endl;

	std::cout << "OVERLOAD OPERATOR" << std::endl;
	std::cout << BureaucratA;

	return (0);
}
