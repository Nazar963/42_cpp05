#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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
	zoro.beSigned(loco);
	std::cout << zoro << std::endl;
	loco.decGrade(10);
	std::cout << loco << std::endl;
	zoro.beSigned(loco);
	std::cout << zoro << std::endl;
	loco.signForm(zoro);
	zoro.execute(loco);
	eren.execute(loco);
	loco.incGrade(15);
	std::cout << loco << std::endl;
	levi.execute(loco);
	Intern someRandomIntern;
	AForm* erwen;
	erwen = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
	if (erwen)
	{
		loco.signForm(*erwen);
		erwen->execute(loco);
		delete erwen;
	}
}