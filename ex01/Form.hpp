#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		const int _gradeSign;
		const int _gradeExecute;
		bool	_isSigned;
	public:
		Form();
		Form(std::string name, int gradeSign, int gradeExecute);
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("grade too high");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("grade too low");
				}
		};
		std::string	getName() const;
		bool	getSigned() const;
		int	getGradeSigned() const;
		int	getGradeExecute() const;

		void	beSigned(Bureaucrat& b);
		~Form();
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif