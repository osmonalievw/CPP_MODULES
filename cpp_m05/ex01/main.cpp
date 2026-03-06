#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat alice("Alice", 40);
        Bureaucrat bob("Bob", 120);
        Form taxForm("TaxForm", 100, 50);

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << taxForm << std::endl;

        bob.signForm(taxForm);
        alice.signForm(taxForm);
        std::cout << taxForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Form invalid("Invalid", 0, 10);
        std::cout << invalid << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}