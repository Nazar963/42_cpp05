#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		const int	_req_sign;
		const int	_exec_sign;
		std::string	_name;
	public:
		ShrubberyCreationForm(std::string name, int gradeSign, int gradeExecute);
		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("tree Grade too high");
				}
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("tree Grade too low");
				}
		};
		void	check(int req, int exec);
		void	loco();
		~ShrubberyCreationForm();
};

#endif