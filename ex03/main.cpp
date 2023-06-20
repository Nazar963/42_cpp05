#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat				loco("loco", 10);
	ShrubberyCreationForm	zoro("zoro");
	RobotomyRequestForm		eren("eren");
	PresidentialPardonForm	levi("levi");

	try
	{
		std::cout << loco << std::endl;
		loco.incGrade(10);
		std::cout << loco << std::endl;
		loco.decGrade(10);
		std::cout << loco << std::endl;
		loco.incGrade(10);
		std::cout << loco << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		zoro.beSigned(loco);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << zoro << std::endl;
	try
	{
		loco.decGrade(20);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << loco << std::endl;
	try
	{
		zoro.beSigned(loco);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << zoro << std::endl;
	loco.signForm(zoro);
	loco.signForm(eren);
	loco.signForm(levi);

	try
	{
		zoro.execute(loco);
		eren.execute(loco);
		loco.incGrade(15);
		std::cout << loco << std::endl;
		levi.execute(loco);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	Intern dog;
	AForm* erwen;
	try
	{
		erwen = dog.makeForm("PresidentialPardonForm", "Bender");
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	if (erwen)
	{
		try
		{
			erwen->beSigned(loco);
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		loco.executeForm(*erwen);
	}
}