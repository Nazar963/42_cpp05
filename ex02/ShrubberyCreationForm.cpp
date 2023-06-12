#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, int gradeSign, int gradeExecute) : _req_sign(145) , _exec_sign(137) , _name(name) , AForm(name, gradeSign, gradeExecute) {}

void	ShrubberyCreationForm::check(int req, int exec)
{
	try
	{
		if (req == _req_sign && exec == _exec_sign)
		{
			std::ofstream fd;
			std::string full = _name + "_shrubbery";
			fd.open(full);
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
		}
		else if (req > _req_sign || exec > _exec_sign)
			throw ShrubberyCreationForm::GradeTooHighException();
		else if (req < _req_sign || exec < _exec_sign)
			throw ShrubberyCreationForm::GradeTooLowException();
	}
	catch (ShrubberyCreationForm::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (ShrubberyCreationForm::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	ShrubberyCreationForm::loco()
{
	std::cout << "hwllo" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}