#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

// int main()
// {
// 	srand(time(NULL));

// 	std::cout << "\n--- CREATING BUREAUCRATS ---" << std::endl;
// 	Bureaucrat boss("Boss", 1);
// 	Bureaucrat intern("Intern", 150);

// 	std::cout << "\n--- SHRUBBERY CREATION FORM ---" << std::endl;

// 	ShrubberyCreationForm home("home");
// 	boss.executeForm(home);
// 	boss.signForm(home);
// 	boss.executeForm(home);
// 	intern.executeForm(home);

// 	std::cout << "\n--- ROBOTOMY REQUEST FORM ---" << std::endl;
// 	RobotomyRequestForm bender("Bender");
// 	boss.signForm(bender);
// 	boss.executeForm(bender);

// 	std::cout
// 			<< "\n--- PRESIDENTIAL PARDON FORM ---" << std::endl;
// 	PresidentialPardonForm ford("Ford Prefect");
// 	boss.signForm(ford);
// 	boss.executeForm(ford);

// 	return 0;
// }

int main()
{
	srand(time(NULL));

	std::cout << "\n=========================================" << std::endl;
	std::cout << "🔥 STRESS TEST 1: HEAP ALLOCATION & POLYMORPHISM 🔥" << std::endl;
	std::cout << "=========================================\n"
						<< std::endl;

	Bureaucrat *god = new Bureaucrat("God", 1);
	Bureaucrat *pleb = new Bureaucrat("Pleb", 150);

	// Allocating derived classes into base class pointers
	AForm *forms[3];
	forms[0] = new ShrubberyCreationForm("Forest");
	forms[1] = new RobotomyRequestForm("Claptrap");
	forms[2] = new PresidentialPardonForm("Arthur Dent");

	std::cout << "\n--- ❌ Attempting to execute unsigned forms ---" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		god->executeForm(*forms[i]);
	}

	std::cout << "\n--- 📝 Signing all forms ---" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		god->signForm(*forms[i]);
	}

	std::cout << "\n--- ❌ Attempting to execute with Pleb (Exceptions expected) ---" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		pleb->executeForm(*forms[i]);
	}

	std::cout << "\n--- ✅ Attempting to execute with God ---" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		god->executeForm(*forms[i]);
	}

	std::cout << "\n--- 🧹 CLEANING UP HEAP MEMORY ---" << std::endl;
	delete god;
	delete pleb;
	for (int i = 0; i < 3; i++)
	{
		delete forms[i]; // If ~AForm is not virtual, this will leak!
	}

	std::cout << "\n=========================================" << std::endl;
	std::cout << "🔥 STRESS TEST 2: EXCEPTION SCOPE LEAKS 🔥" << std::endl;
	std::cout << "=========================================\n"
						<< std::endl;

	// Testing if an exception thrown mid-execution breaks memory scope
	try
	{
		Bureaucrat midTier("MidTier", 50);
		PresidentialPardonForm doomedForm("Doomed");

		midTier.signForm(doomedForm); // Will fail, throws GradeTooLowException
		midTier.executeForm(doomedForm);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught an unexpected fatal error in scope test: " << e.what() << std::endl;
	}

	std::cout << "\n=========================================" << std::endl;
	std::cout << "🔥 STRESS TEST 3: MASS CREATION 🔥" << std::endl;
	std::cout << "=========================================\n"
						<< std::endl;

	std::cout << "Creating and destroying 100 Robotomy forms instantly..." << std::endl;
	for (int i = 0; i < 100; i++)
	{
		RobotomyRequestForm temp("TestSubject");
	}
	std::cout << "Done." << std::endl;

	std::cout << "\n--- END OF TESTS ---" << std::endl;
	return 0;
}
