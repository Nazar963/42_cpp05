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
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

AForm::AForm(const AForm& copy) : _name(copy._name), _gradeSign(copy._gradeSign), _gradeExecute(copy._gradeExecute) {}

AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

std::string AForm::getName() const { return (_name); }

bool	AForm::getSigned() const { return (_isSigned); }

int	AForm::getGradeSigned() const { return (_gradeSign); }

int	AForm::getGradeExecute() const { return (_gradeExecute); }

void	AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= _gradeSign)
		_isSigned = true;
	else if (b.getGrade() > _gradeSign)
	{
		_isSigned = false;
		throw AForm::GradeTooLowException();
	}
}

AForm::~AForm() {}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "name of the form is " << f.getName() << std::endl;
	os << "grade required to be signed " << f.getGradeSigned() << std::endl;
	os << "grade required to be executed " << f.getGradeExecute() << std::endl;
	os << "status of the form " << f.getSigned();
	return (os);
}