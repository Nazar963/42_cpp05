#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_name;
	public:
		RobotomyRequestForm(std::string name);
		class HighException: public std::exception
		{
			public:
				const char* what() const throw()
				{
					return (" robotomy failed");
				}
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("robotomy grade too low");
				}
		};
		void	execute(Bureaucrat const & executor) const;
		~RobotomyRequestForm();
};

#endif