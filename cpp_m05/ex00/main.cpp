#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	// ------------------------------------------------------------------
	// TEST 1: STANDARD USAGE
	// ------------------------------------------------------------------
	std::cout << "\n--- TEST 1: Standard Construction & Output ---" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl; // Testing operator<<

		std::cout << "Incrementing Bob..." << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl;

		std::cout << "Decrementing Bob..." << std::endl;
		bob.decrementGrade();
		std::cout << bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// ------------------------------------------------------------------
	// TEST 2: CONSTRUCTOR FAILURE (TOO HIGH)
	// ------------------------------------------------------------------
	std::cout << "\n--- TEST 2: Constructing with Grade 0 (Too High) ---" << std::endl;
	try
	{
		// This should throw GradeTooHighException because 0 < 1
		Bureaucrat god("God", 0);
		std::cout << "This line should NOT print." << std::endl;
	}
	catch (std::exception &e)
	{
		// We catch the specific error here
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// ------------------------------------------------------------------
	// TEST 3: CONSTRUCTOR FAILURE (TOO LOW)
	// ------------------------------------------------------------------
	std::cout << "\n--- TEST 3: Constructing with Grade 151 (Too Low) ---" << std::endl;
	try
	{
		// This should throw GradeTooLowException because 151 > 150
		Bureaucrat peasant("Peasant", 151);
		std::cout << "This line should NOT print." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// ------------------------------------------------------------------
	// TEST 4: INCREMENT FAILURE
	// ------------------------------------------------------------------
	std::cout << "\n--- TEST 4: Incrementing Grade 1 (Error) ---" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		std::cout << boss << std::endl;

		std::cout << "Attempting to increment grade 1..." << std::endl;
		boss.incrementGrade(); // Should throw GradeTooHighException

		std::cout << "This line should NOT print." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// ------------------------------------------------------------------
	// TEST 5: DECREMENT FAILURE
	// ------------------------------------------------------------------
	std::cout << "\n--- TEST 5: Decrementing Grade 150 (Error) ---" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		std::cout << intern << std::endl;

		std::cout << "Attempting to decrement grade 150..." << std::endl;
		intern.decrementGrade(); // Should throw GradeTooLowException

		std::cout << "This line should NOT print." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}