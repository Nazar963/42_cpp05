#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		std::string	_name;
	public:
		Intern();
		AForm*	makeForm(std::string name, std::string target);
		~Intern();
};

#endif