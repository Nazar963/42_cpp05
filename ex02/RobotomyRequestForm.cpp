#include <iostream>
#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm("RobotomyRequestForm", 72, 45), _name(name) {}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() <= getGradeExecute())
		{
			srand(time(NULL));
			int	random_num = rand();
			std::cout << "drilling noises " << std::endl;
			if (random_num < RAND_MAX / 2)
				std::cout << _name << " has been robotomized successfully" << std::endl;
			else
				throw RobotomyRequestForm::HighException();
		}
		else
			throw RobotomyRequestForm::GradeTooLowException();
	}
	catch (RobotomyRequestForm::HighException& e)
	{
		std::cout << _name << e.what() << std::endl;
	}
	catch (RobotomyRequestForm::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}



RobotomyRequestForm::~RobotomyRequestForm(){}