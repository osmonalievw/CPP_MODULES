#include <iostream>

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat alice("Alice", 2);
        Bureaucrat bob("Bob", 150);

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;

        alice.incrementGrade();
        bob.decrementGrade();

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat invalid("Invalid", 0);
        std::cout << invalid << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}