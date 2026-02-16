#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

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

	std::cout << "\n--- Invalid Form test ---" << std::endl;
	try
	{
		Form invalid("Invalid", 0, 10);
		std::cout << invalid << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "\n--- Invalid Bureaucrat test ---" << std::endl;
	try
	{
		Bureaucrat invalid_b("Ken", 160);
		Bureaucrat invalid_a("Kenb", -160);
		std::cout << invalid_b << std::endl;
		std::cout << invalid_a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "out: " << e.what() << std::endl;
		std::cerr << "out: " << e.what() << std::endl;
	}
	return 0;
}