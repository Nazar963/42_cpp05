#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	loco("loco", 10);
	Form	zoro("zoro", 20, 10);

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
	catch (Form::GradeTooLowException& e)
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
	catch (Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << zoro << std::endl;
	loco.signForm(zoro);
}