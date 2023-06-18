#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm("ShrubberyCreationForm", 145, 137), _name(name) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy)
{
	_name = copy._name;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_name = other._name;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
		if (this->getSigned())
		{
			if (executor.getGrade() <= this->getGradeExecute())
			{
				std::ofstream fd;
				std::string full = _name + "_shrubbery";
				fd.open(full.c_str());
				fd << "	                                               .      " << std::endl;
				fd << "                                     .         ;       " << std::endl;
				fd << "        .              .              ;%     ;;        " << std::endl;
				fd << "          ,           ,                :;%  %;         " << std::endl;
				fd << "           :         ;                   :;%;'     .,  " << std::endl;
				fd << "  ,.        %;     %;            ;        %;'    ,;    " << std::endl;
				fd << "    ;       ;%;  %%;        ,     %;    ;%;    ,%'     " << std::endl;
				fd << "     %;       %;%;      ,  ;       %;  ;%;   ,%;'      " << std::endl;
				fd << "      ;%;      %;        ;%;        % ;%;  ,%;'        " << std::endl;
				fd << "       `%;.     ;%;     %;'         `;%%;.%;'          " << std::endl;
				fd << "        `:;%.    ;%%. %@;        %; ;@%;%'             " << std::endl;
				fd << "           `:%;.  :;bd%;          %;@%;'               " << std::endl;
				fd << "             `@%:.  :;%.         ;@@%;'                " << std::endl;
				fd << "               `@%.  `;@%.      ;@@%;                  " << std::endl;
				fd << "                 `@%%. `@%%    ;@@%;                   " << std::endl;
				fd << "                   ;@%. :@%%  %@@%;                    " << std::endl;
				fd << "                     %@bd%%%bd%%:;                     " << std::endl;
				fd << "                       #@%%%%%:;;                      " << std::endl;
				fd << "                       %@@%%%::;                       " << std::endl;
				fd << "                       %@@@%(o);  . '                  " << std::endl;
				fd << "                       %@@@o%;:(.,'                    " << std::endl;
				fd << "                   `.. %@@@o%::;                       " << std::endl;
				fd << "                      `)@@@o%::;                       " << std::endl;
				fd << "                       %@@(o)::;                       " << std::endl;
				fd << "                      .%@@@@%::;                       " << std::endl;
				fd << "                      ;%@@@@%::;.                      " << std::endl;
				fd << "                     ;%@@@@%%:;;;.                     " << std::endl;
				fd << "                 ...;%@@@@@%%:;;;;,..                  " << std::endl;
				fd.close();
			}
			else
			{
				throw AForm::GradeTooLowException();
				return ;
			}
		}
		else
			throw AForm::FormNotSigned();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}