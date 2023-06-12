#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	Bureaucrat	loco("loco", 10);
	ShrubberyCreationForm	zoro("zoro");
	RobotomyRequestForm		eren("eren");

	std::cout << loco << std::endl;
	loco.incGrade(10);
	std::cout << loco << std::endl;
	loco.decGrade(10);
	std::cout << loco << std::endl;
	loco.incGrade(10);
	std::cout << loco << std::endl;
	zoro.beSigned(loco);
	std::cout << zoro << std::endl;
	loco.decGrade(10);
	std::cout << loco << std::endl;
	zoro.beSigned(loco);
	std::cout << zoro << std::endl;
	loco.signForm(zoro);
	zoro.check(zoro.getGradeSigned(), zoro.getGradeExecute());
	zoro.
}