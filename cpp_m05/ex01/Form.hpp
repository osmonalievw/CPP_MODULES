#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    Form(void);
    Form(std::string Name, int rankSign, int rankExec);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    const std::string getName() const;
    bool getSignInfo() const;
    int getSignGrade() const;
    int getExecGrade() const;

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

    void beSigned(Bureaucrat &v);
};

std::ostream &operator<<(std::ostream &out, const Form &b);

#endif
