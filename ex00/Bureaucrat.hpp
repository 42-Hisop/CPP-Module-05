#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private :
		std::string const _name;
		int	_grade;
	public :
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		virtual ~Bureaucrat();
		
		const std::string getName(void) const;
		int	getGrade(void) const;
		
		void	incrGrade(void);
		void	decrGrade(void);

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

		Bureaucrat &operator=(const Bureaucrat &other);
};

std::ostream &operator<<(std::ostream &flux, const Bureaucrat &src);

#endif
