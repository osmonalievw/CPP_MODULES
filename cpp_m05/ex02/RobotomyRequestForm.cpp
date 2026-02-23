#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("default_target")
{
    std::cout << "🤖 RobotomyRequestForm Default Constructor called for target: " << this->_target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "🤖 RobotomyRequestForm Parameterized Constructor called for target: " << this->_target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{
    std::cout << "🤖 RobotomyRequestForm Copy Constructor called for target: " << this->_target << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "🤖 RobotomyRequestForm Assignment Operator called for target: " << other._target << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "🛠️ RobotomyRequestForm Destructor called for target: " << this->_target << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    checkExecutionRequirements(executor);
    std::cout << "* BZZZZZZZZT! VRRRRRR! *" << std::endl;
    if (rand() % 2 == 1)
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "robotomy failed" << std::endl;
}