	#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm("ShrubberyCreationForm", 145, 137), _name(name) {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() <= getGradeExecute())
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
			throw ShrubberyCreationForm::GradeTooLowException();
	}
	catch (ShrubberyCreationForm::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}