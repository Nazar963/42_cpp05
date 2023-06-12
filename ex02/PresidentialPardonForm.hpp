#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_name;
	public:
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Grade too low");
				}
		};
		PresidentialPardonForm(std::string target);
		void	execute(Bureaucrat const & executor) const;
		~PresidentialPardonForm();
};

#endif