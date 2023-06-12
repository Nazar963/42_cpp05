#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			_grade = grade;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::string	Bureaucrat::getName() const	{ return (_name); }

int	Bureaucrat::getGrade() const	{ return (_grade); }

void	Bureaucrat::incGrade(int num)
{
	try
	{
		if ((_grade - num) < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			_grade -= num;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::decGrade(int num)
{
	try
	{
		if (_grade + num > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			_grade += num;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::signForm(AForm& e)
{
	if (e.getSigned())
		std::cout << _name << " signed " << e.getName() << std::endl;
	else
	{
		if (Bureaucrat::getGrade() < e.getGradeSigned())
			std::cout << _name << " signed " << e.getName() << " grade required too high" << std::endl;
		else if (Bureaucrat::getGrade() > e.getGradeSigned())
			std::cout << _name << " signed " << e.getName() << " grade required too high" << std::endl;
	}

}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& f)
{
	os << f.getName() << ", bureaucrat grade " << f.getGrade();
	return (os);
}

Bureaucrat::~Bureaucrat()	{}
