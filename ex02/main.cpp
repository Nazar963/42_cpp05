#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	loco("loco", 10);
	ShrubberyCreationForm	zoro("zoro");
	RobotomyRequestForm		eren("eren");
	PresidentialPardonForm	levi("levi");

	std::cout << loco << std::endl;
	loco.incGrade(10);
	std::cout << loco << std::endl;
	loco.decGrade(10);
	std::cout << loco << std::endl;
	loco.incGrade(10);
	std::cout << loco << std::endl;

	try
	{
		zoro.beSigned(loco);
	}
	catch (AForm::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << zoro << std::endl;
	loco.decGrade(20);
	std::cout << loco << std::endl;
	try
	{
		zoro.beSigned(loco);
	}
	catch (AForm::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << zoro << std::endl;
	try
	{
		loco.signForm(zoro);
		loco.signForm(eren);
		loco.signForm(levi);
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		zoro.execute(loco);
		eren.execute(loco);
		loco.incGrade(15);
		std::cout << loco << std::endl;
		levi.execute(loco);
	}
	catch (AForm::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::FormNotSigned& e)
	{
		std::cout << e.what() << std::endl;
	}
}