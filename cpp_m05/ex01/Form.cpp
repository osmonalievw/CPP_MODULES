#include "Form.hpp"
#include "Bureaucrat.hpp"

// Default constructor
Form::Form(void) : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Default constructor called" << std::endl;
}

Form::Form(std::string Name, int rankSign, int rankExec) : _name(Name), _isSigned(false), _gradeToSign(rankSign), _gradeToExecute(rankExec)
{
    if (_gradeToExecute < 1 || _gradeToSign < 1)
        throw Form::GradeTooHighException();
    if (_gradeToExecute > 150 || _gradeToSign > 150)
        throw Form::GradeTooLowException();
    std::cout << "Parameter constructor called" << std::endl;
}

// Copy constructor
Form::Form(const Form &other) : _name(other._name),
                                _isSigned(other._isSigned),
                                _gradeToSign(other._gradeToSign),
                                _gradeToExecute(other._gradeToExecute)
{
    std::cout << "Copy constructor called" << std::endl;
}

// Assignment operator overload
Form &Form::operator=(const Form &other)
{
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
        this->_isSigned = other._isSigned;
    return (*this);
}

// Destructor
Form::~Form(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

const std::string Form::getName() const
{
    return this->_name;
}

bool Form::getSignInfo() const
{
    return this->_isSigned;
}

int Form::getSignGrade() const
{
    return this->_gradeToSign;
}

int Form::getExecGrade() const
{
    return this->_gradeToExecute;
}

void Form::beSigned(Bureaucrat &v)
{
    if (v.getGrade() > this->getSignGrade())
        throw Form::GradeTooLowException();
    _isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Form &b)
{
    out << "Form: " << b.getName()
        << ", Signed: " << (b.getSignInfo() ? "Yes" : "No")
        << ", Grade to sign: " << b.getSignGrade()
        << ", Grade to execute: " << b.getExecGrade();
    return out;
}