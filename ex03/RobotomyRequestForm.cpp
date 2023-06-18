#include <iostream>
#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm("RobotomyRequestForm", 72, 45), _name(name) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy)
{
	_name = copy._name;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_name = other._name;
	}
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned())
	{
		if (executor.getGrade() <= this->getGradeExecute())
		{
			srand(time(NULL));
			int	num = rand();
			std::cout << "drilling noises " << std::endl;
			if (num < RAND_MAX / 2)
				std::cout << _name << " has been robotomized successfully" << std::endl;
			else
				std::cout << "robotomy failed on " << _name << std::endl;
		}
		else
		{
			throw AForm::GradeTooLowException();
			return ;
		}
	}
	else
		throw AForm::FormNotSigned();
}

RobotomyRequestForm::~RobotomyRequestForm(){}