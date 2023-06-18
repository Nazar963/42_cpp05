#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& copy)
{
	_name = copy._name;
}

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other)
		_name = other._name;
	return (*this);
}

AForm* createPresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* createRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* createShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	struct FormCreator {
		std::string name;
		AForm* (*creator)(std::string);
	};

	FormCreator formCreators[] = {
		{"PresidentialPardonForm", createPresidentialPardonForm},
		{"RobotomyRequestForm", createRobotomyRequestForm},
		{"ShrubberyCreationForm", createShrubberyCreationForm}
	};

	for (size_t i = 0; i < 4; i++)
	{
		if (formCreators[i].name == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (formCreators[i].creator(target));
		}
	}

	std::cout << "Form not found" << std::endl;
	return (NULL);
}

Intern::~Intern() {}