#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_name;
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);

		void	execute(Bureaucrat const & executor) const;

		~RobotomyRequestForm();
};

#endif