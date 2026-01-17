#ifndef Animal_HPP
#define Animal_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
    std::string type;

public:
    Animal();
    Animal(std::string _type);
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    virtual ~Animal();
    std::string getType() const;
    virtual void makeSound() const = 0;
};

#endif