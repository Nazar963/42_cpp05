#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat				loco("loco", 20);
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
	catch(const std::exception& e)
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
	loco.executeForm(zoro);
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
}