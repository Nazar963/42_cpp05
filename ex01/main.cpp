#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	loco("loco", 10);
	Form	zoro("zoro", 20, 10);

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
	try
	{
		std::cout << zoro << std::endl;
		loco.decGrade(20);
		std::cout << loco << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		zoro.beSigned(loco);
		std::cout << zoro << std::endl;
		loco.signForm(zoro);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}