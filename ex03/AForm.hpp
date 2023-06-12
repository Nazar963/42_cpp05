#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		const int _gradeSign;
		const int _gradeExecute;
		bool	_isSigned;
	public:
		AForm(std::string name, int gradeSign, int gradeExecute);
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Form grade too high");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Form grade too low");
				}
		};
		std::string	getName() const;
		bool	getSigned() const;
		int	getGradeSigned() const;
		int	getGradeExecute() const;
		virtual void	execute(Bureaucrat const & executor) const = 0;

		void	beSigned(Bureaucrat& b);
		virtual  ~AForm();
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif