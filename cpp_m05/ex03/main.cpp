#include <cstdlib>
#include <ctime>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    srand(time(NULL));

    try
    {
        Intern intern;
        Bureaucrat boss("Boss", 1);

        AForm *rrf = intern.makeForm("robotomy request", "Bender");
        AForm *scf = intern.makeForm("shrubbery creation", "Home");
        AForm *ppf = intern.makeForm("presidential pardon", "Arthur Dent");

        AForm *forms[3] = {rrf, scf, ppf};
        for (int i = 0; i < 3; i++)
        {
            if (forms[i])
            {
                boss.signForm(*forms[i]);
                boss.executeForm(*forms[i]);
                delete forms[i];
            }
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}