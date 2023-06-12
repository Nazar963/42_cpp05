#include "AForm.hpp"

AForm::AForm(std::string name, int gradeSign, int gradeExecute) : _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute), _isSigned(false) 
{
	try
	{
		if (gradeSign < 1 || gradeExecute < 1)
			throw AForm::GradeTooHighException();
		else if (gradeSign > 150 || gradeExecute > 150)
			throw AForm::GradeTooLowException();
	}
	catch (AForm::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::string AForm::getName() const { return (_name); }

bool	AForm::getSigned() const { return (_isSigned); }

int	AForm::getGradeSigned() const { return (_gradeSign); }

int	AForm::getGradeExecute() const { return (_gradeExecute); }

void	AForm::beSigned(Bureaucrat& b)
{
	try
	{
		if (b.getGrade() <= _gradeSign)
			_isSigned = true;
		else if (b.getGrade() > _gradeSign)
			throw AForm::GradeTooLowException();
	}
	catch (AForm::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

AForm::~AForm() {}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "staus of isSigned is " << f.getSigned();
	return (os);
}