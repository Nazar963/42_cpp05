#include <iostream>
#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 10, 10), _req_sign(72), _exec_sign(45) , _name(name) {}

void	RobotomyRequestForm::check(int req, int exec)
{
	try
	{
		if (req == _req_sign && exec == _exec_sign)
		{
			int	random_num = rand();
			std::cout << "drilling noises " << std::endl;
			if (random_num < RAND_MAX / 2)
				std::cout << _name << " has been robotomized successfully" << std::endl;
			else
				throw RobotomyRequestForm::HighException();
		}
		else if (req > _req_sign || exec > _exec_sign)
			throw RobotomyRequestForm::GradeTooHighException();
		else if (req < _req_sign || exec < _exec_sign)
			throw RobotomyRequestForm::GradeTooLowException();
	}
	catch (RobotomyRequestForm::HighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (RobotomyRequestForm::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (RobotomyRequestForm::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	RobotomyRequestForm::loco(){}

RobotomyRequestForm::~RobotomyRequestForm(){}