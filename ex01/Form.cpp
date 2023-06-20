#include "Form.hpp"

Form::Form() : _name(""), _gradeSign(0), _gradeExecute(0), _isSigned(false) {}

Form::Form(std::string name, int gradeSign, int gradeExecute) : _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	try
	{
		if (gradeSign < 1 || gradeExecute < 1)
			throw Form::GradeTooHighException();
		else if (gradeSign > 150 || gradeExecute > 150)
			throw Form::GradeTooLowException();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::string Form::getName() const { return (_name); }

bool	Form::getSigned() const { return (_isSigned); }

int	Form::getGradeSigned() const { return (_gradeSign); }

int	Form::getGradeExecute() const { return (_gradeExecute); }

void	Form::beSigned(Bureaucrat& b)
{
		if (b.getGrade() <= _gradeSign)
			_isSigned = true;
		else if (b.getGrade() > _gradeSign)
		{
			_isSigned = false;
			throw Form::GradeTooLowException();
		}
}

Form::~Form() {}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "name of the form is " << f.getName() << std::endl;
	os << "grade required to be signed " << f.getGradeSigned() << std::endl;
	os << "grade required to be executed " << f.getGradeExecute() << std::endl;
	os << "status of the form " << f.getSigned();
	return (os);
}