#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const int	_req_sign;
		const int	_exec_sign;
		std::string	_name;
	public:
		RobotomyRequestForm(std::string name);
		class HighException: public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("robotomy failed");
				}
		};
		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("robotomy grade too high");
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
		void	check(int req, int exec);
		void	loco();
		~RobotomyRequestForm();
};

#endif