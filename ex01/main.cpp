#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat	randomB;
	Bureaucrat	badB1("BadB1", 0);
	Bureaucrat	badB2("BadB2", 153);
	Bureaucrat	A("Aaa", 120);
	Bureaucrat	B("Bbb", 12);
	Bureaucrat	C("Ccc", 67);
	std::cout << std::endl;
	
	Form	randomForm;
	Form	badF1("BadF1", 0, 122);
	Form	badF2("BadF2", 151, 100);
	Form	badF3("BadF3", 23, 160);
	Form	Form1("Form1", 13, 4);
	Form	Form2("Form2", 45, 45);
	Form	Form3("Form3", 100, 60);

	std::cout << randomForm << std::endl;
	std::cout << badF1 << std::endl;
	std::cout << badF2 << std::endl;
	std::cout << badF3 << std::endl;
	std::cout << Form1 << std::endl;
	std::cout << Form2 << std::endl;
	std::cout << Form3 << std::endl;
	
	A.signForm(randomForm);
	B.signForm(Form1);
	C.signForm(Form2);
	C.signForm(Form3);
	return (0);
}
