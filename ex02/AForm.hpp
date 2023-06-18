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
		AForm();
	public:
		AForm(std::string name, int gradeSign, int gradeExecute);
		AForm(const AForm& copy);
		AForm&	operator=(const AForm& other);

		std::string		getName() const;
		bool			getSigned() const;
		int				getGradeSigned() const;
		int				getGradeExecute() const;
		virtual void	execute(Bureaucrat const & executor) const = 0;
		void			beSigned(Bureaucrat& b);

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
		class FormNotSigned : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("the form required is not signed");
				}
		};

		~AForm();
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif