#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    AForm(void);
    AForm(std::string Name, int rankSign, int rankExec);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    const std::string getName() const;
    bool getSignInfo() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(Bureaucrat &v);

    virtual void execute(Bureaucrat const &executor) const = 0;

    void checkExecutionRequirements(Bureaucrat const &executor) const;

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class NotSignedException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &b);

#endif
