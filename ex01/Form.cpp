#include "Form.hpp"

Form::Form(std::string name, int gradeSign, int gradeExecute) : _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute), _isSigned(false) {}

std::string Form::getName() const { return (_name); }

bool	Form::getSigned() const { return (_isSigned); }

int	Form::getGradeSigned() const { return (_gradeSign); }

int	Form::getGradeExecute() const { return (_gradeExecute); }

void	Form::beSigned(Bureaucrat& b)
{
	try
	{
		if (b.getGrade() == _gradeSign)
			_isSigned = true;
		else if (b.getGrade() < _gradeSign)
			throw Form::GradeTooHighException();
		else if (b.getGrade() > _gradeSign)
			throw Form::GradeTooLowException();
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

}

Form::~Form() {}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "staus of isSigned is " << f.getSigned();
	return (os);
}