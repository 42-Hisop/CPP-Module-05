#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private :
		std::string const _name;
		int	const	_signedGrade;
		int	const	_execGrade;
		bool	_signed;

	public:
		Form(void);
		Form(std::string name, int signedGrade, int execGrade);
		Form(const Form &src);
		virtual ~Form();
		
		const std::string	getName(void) const;
		int	getSignedGrade(void) const;
		int	getExecGrade(void) const;
		bool getSigned(void) const;
		
		void	checkGrade(int signedGrade, int execGrade);
		bool	beSigned(Bureaucrat const &bureaucrat);
		virtual bool checkSignature(const Bureaucrat &executor) const;
		virtual bool execute(const Bureaucrat &executor) const = 0;
		
		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char *what() const throw()
				{
					return ("high Grade");
				}
		};

		class GradeTooLowException : public std::exception
		{	
			public :
				virtual const char *what() const throw()
				{
					return ("low Grade");
				}
		};

		class cannotSigned : public std::exception
		{
			public :
				virtual const char *what() const throw()
				{
					return ("can not be signed");
				}
		};	
		Form &operator=(const Form &other);
};
std::ostream	&operator<<(std::ostream &flux, const Form &src);

#endif
