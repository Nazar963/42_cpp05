#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm("PresidentialPardonForm", 25, 5), _name(name) {}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() <= getGradeExecute())
			std::cout << _name << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		else
			throw PresidentialPardonForm::GradeTooLowException();
	}
	catch(PresidentialPardonForm::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

PresidentialPardonForm::~PresidentialPardonForm() {}