#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_name;
	public:
		ShrubberyCreationForm(std::string name);
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("tree Grade too low");
				}
		};
		void	execute(Bureaucrat const & executor) const;
		~ShrubberyCreationForm();
};

#endif