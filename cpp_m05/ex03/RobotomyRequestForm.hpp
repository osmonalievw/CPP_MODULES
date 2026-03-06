#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
   private:
    std::string _target;

   public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(std::string const& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const& executor) const;
};

#endif