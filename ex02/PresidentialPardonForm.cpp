#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm("PresidentialPardonForm", 25, 5), _name(name) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy)
{
	_name = copy._name;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_name = other._name;
	}
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned())
	{
		if (executor.getGrade() <= this->getGradeExecute())
			std::cout << _name << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		else
		{
			throw AForm::GradeTooLowException();
			return ;
		}
	}
	else
		throw AForm::FormNotSigned();
}

PresidentialPardonForm::~PresidentialPardonForm() {}