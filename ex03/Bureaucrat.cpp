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

void	Bureaucrat::signForm(AForm& boh)
{
	try
	{
		if (boh.getSigned())
			std::cout << _name << " signed " << boh.getName() << std::endl;
		else
		{
			if (_grade < boh.getGradeSigned())
				throw Bureaucrat::GradeTooHighException();
			else if (_grade > boh.getGradeSigned())
				throw Bureaucrat::GradeTooLowException();
		}
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << _name << " couldn't sign " << boh.getName() << "because" << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & boh)
{
	try
	{
		if (boh.getSigned())
		{
			if (_grade <= boh.getGradeExecute())
				std::cout << _name << " executed " << boh.getName() << std::endl;
			else
				throw Bureaucrat::GradeTooLowException();
		}
		else
			throw Bureaucrat::NotSignedException();
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << _name << " couldn't execute " << boh.getName() << " because " << e.what() << std::endl;
	}
	catch (Bureaucrat::NotSignedException& e)
	{
		std::cout << _name << " couldn't execute " << boh.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& f)
{
	os << f.getName() << ", bureaucrat grade " << f.getGrade();
	return (os);
}

Bureaucrat::~Bureaucrat()	{}