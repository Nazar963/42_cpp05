	#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 10, 10), _req_sign(145), _exec_sign(137) , _name(name) {}

void	ShrubberyCreationForm::check(int req, int exec)
{
	try
	{
		if (req == _req_sign && exec == _exec_sign)
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