#include "Intern.hpp"

Intern::Intern() { std::cout << "Intern Default Constructor called" << std::endl; }

Intern::Intern(const Intern &other)
{
    std::cout << "Intern Copy Constructor called" << std::endl;
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    std::cout << "Intern Copy Assignment Operator called" << std::endl;
    if (this != &other)
    {
        // Nothing to copy, Intern has no attributes
    }
    return (*this);
}

Intern::~Intern() { std::cout << "Intern Destructor called" << std::endl; }

AForm *Intern::makeShrubbery(const std::string target) const { return (new ShrubberyCreationForm(target)); }
AForm *Intern::makeRobotomy(const std::string target) const { return (new RobotomyRequestForm(target)); }
AForm *Intern::makePardon(const std::string target) const { return (new PresidentialPardonForm(target)); }

AForm *Intern::makeForm(const std::string formRequest, const std::string target) const
{
    std::string arr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    typedef AForm *(Intern::*func_ptr)(const std::string target) const;
    func_ptr Table[] = {
        &Intern::makeShrubbery,
        &Intern::makeRobotomy,
        &Intern::makePardon,
    };
    for (int i = 0; i < 3; i++)
    {
        if (arr[i] == formRequest)
        {
            std::cout << "Intern creates " << formRequest << std::endl;
            return (this->*Table[i])(target);
        }
    }
    std::cout << "Intern couldn't create " << formRequest << " because it doesn't exist" << std::endl;
    return (NULL);
}
