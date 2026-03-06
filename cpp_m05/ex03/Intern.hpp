#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
   private:
    AForm* makeShrubbery(const std::string target) const;
    AForm* makeRobotomy(const std::string target) const;
    AForm* makePardon(const std::string target) const;

   public:
    Intern(void);
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string formRequest, const std::string target) const;
};

#endif
