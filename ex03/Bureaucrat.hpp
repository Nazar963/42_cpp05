#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Grade too high");
				}
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Grade too low");
				}
		};
		Bureaucrat(std::string name, int grade);
		void	executeForm(AForm const & form);

		std::string	getName() const;
		int			getGrade() const;
		void		incGrade(int num);
		void		decGrade(int num);
		void		signForm(AForm& e);
		~Bureaucrat();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& f);

#endif