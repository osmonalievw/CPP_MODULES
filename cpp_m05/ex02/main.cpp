#include <cstdlib>
#include <ctime>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    srand(time(NULL));

    try
    {
        Bureaucrat signer("Signer", 1);
        Bureaucrat executor("Executor", 1);

        AForm *forms[3];
        forms[0] = new ShrubberyCreationForm("Forest");
        forms[1] = new RobotomyRequestForm("Claptrap");
        forms[2] = new PresidentialPardonForm("Arthur Dent");

        for (int i = 0; i < 3; i++)
        {
            signer.signForm(*forms[i]);
            executor.executeForm(*forms[i]);
            delete forms[i];
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
