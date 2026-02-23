#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Default constructor
AForm::AForm(void) : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(std::string Name, int rankSign, int rankExec) : _name(Name), _isSigned(false), _gradeToSign(rankSign), _gradeToExecute(rankExec)
{
    if (_gradeToExecute < 1 || _gradeToSign < 1)
        throw AForm::GradeTooHighException();
    if (_gradeToExecute > 150 || _gradeToSign > 150)
        throw AForm::GradeTooLowException();
    std::cout << "Parameter constructor called" << std::endl;
}

// Copy constructor
AForm::AForm(const AForm &other) : _name(other._name),
                                   _isSigned(other._isSigned),
                                   _gradeToSign(other._gradeToSign),
                                   _gradeToExecute(other._gradeToExecute)
{
    std::cout << "Copy constructor called" << std::endl;
}

// Assignment operator overload
AForm &AForm::operator=(const AForm &other)
{
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
        this->_isSigned = other._isSigned;
    return (*this);
}

// Destructor
AForm::~AForm(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

const std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::getSignInfo() const
{
    return this->_isSigned;
}

int AForm::getSignGrade() const
{
    return this->_gradeToSign;
}

int AForm::getExecGrade() const
{
    return this->_gradeToExecute;
}

void AForm::beSigned(Bureaucrat &v)
{
    if (v.getGrade() > this->getSignGrade())
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

void AForm::checkExecutionRequirements(Bureaucrat const &executor) const
{
    if (this->_isSigned == false)
        throw AForm::NotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade is too low";
}

const char *AForm::NotSignedException::what() const throw()
{
    return "AForm is not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &b)
{
    out << "AForm: " << b.getName()
        << ", Signed: " << (b.getSignInfo() ? "Yes" : "No")
        << ", Grade to sign: " << b.getSignGrade()
        << ", Grade to execute: " << b.getExecGrade();
    return out;
}