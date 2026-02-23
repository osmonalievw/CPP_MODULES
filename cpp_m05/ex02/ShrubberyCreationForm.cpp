#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("default_target")
{
  std::cout << "🌲 ShrubberyCreationForm Default Constructor called for target: " << this->_target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
  std::cout << "🌲 ShrubberyCreationForm Parameterized Constructor called for target: " << this->_target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
  std::cout << "🌲 ShrubberyCreationForm Copy Constructor called for target: " << this->_target << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
  std::cout << "🌲 ShrubberyCreationForm Assignment Operator called for target: " << other._target << std::endl;
  if (this != &other)
  {
    AForm::operator=(other);
    this->_target = other._target;
  }
  return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
  std::cout << "🪓 ShrubberyCreationForm Destructor called for target: " << this->_target << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
  this->checkExecutionRequirements(executor);

  std::ofstream file((this->_target + "_shrubbery").c_str());

  file << "*             ," << std::endl;
  file << "                  _/^\\_" << std::endl;
  file << "                 <     >" << std::endl;
  file << "*                 /.-.\\         *" << std::endl;
  file << "         *        `/&\\`                   *" << std::endl;
  file << "                 ,@.*;@," << std::endl;
  file << "                /_o.I %_\\    *" << std::endl;
  file << "   *           (`'--:o(_@;" << std::endl;
  file << "              /`;--.,__ `')             *" << std::endl;
  file << "             ;@`o % O,*`'`&\\" << std::endl;
  file << "       *    (`'--)_@ ;o %'()\\      *" << std::endl;
  file << "            /`;--._`''--._O'@;" << std::endl;
  file << "           /&*,()~o`;-.,_ `\"\"`)" << std::endl;
  file << "*          /`,@ ;+& () o*`;-';\\" << std::endl;
  file << "          (`\"\"--.,_0 +% @' &()\\" << std::endl;
  file << "          /-.,_    ``''--....-'`)  *" << std::endl;
  file << "     *    /@%;o`:;'--,.__   __.'\\" << std::endl;
  file << "         ;*,&(); @ % &^;~`\"`o;@();         *" << std::endl;
  file << "         /(); o^~; & ().o@*&`;&%O\\" << std::endl;
  file << "   jgs   `\"=\"==\"\"==,,,.,=\"==\"==\"`" << std::endl;
  file << "      __.----.(\\-''#####---...___...-----._" << std::endl;
  file << "    '`         \\)_`\"\"\"\"`" << std::endl;

  file.close();
}