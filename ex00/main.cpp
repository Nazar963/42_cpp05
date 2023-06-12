#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	loco("loco", 10);

	std::cout << loco << std::endl;
	loco.incGrade(10);
	std::cout << loco << std::endl;
	loco.decGrade(10);
	std::cout << loco << std::endl;
}