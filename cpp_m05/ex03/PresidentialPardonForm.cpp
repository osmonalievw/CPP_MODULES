#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("PresidentialPardonForm", 25, 5), _target("default_target") {
    std::cout << "📜 PresidentialPardonForm Default Constructor called for target: " << this->_target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << "📜 PresidentialPardonForm Parameterized Constructor called for target: " << this->_target
              << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target) {
    std::cout << "📜 PresidentialPardonForm Copy Constructor called for target: " << this->_target << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    std::cout << "📜 PresidentialPardonForm Assignment Operator called for target: " << other._target << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "🗑️ PresidentialPardonForm Destructor called for target: " << this->_target << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    this->checkExecutionRequirements(executor);

    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}