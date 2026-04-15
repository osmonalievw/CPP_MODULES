#include "Base.hpp"

Base::~Base()
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Base *Base::generate(void)
{
	static A a;
	static B b;
	static C c;
	return (Base *[]){&a, &b, &c}[std::rand() % 3];
}

void Base::identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "p: " << getName<A>() << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "p: " << getName<B>() << std::endl;
	else if (dynamic_cast<B *>(p))
		std ::cout << "p: " << getName<C>() << std::endl;
}
void Base::identify(Base &p)
{
	if (dynamic_cast<A *>(&p))
		std::cout << "p: " << getName<A>() << std::endl;
	else if (dynamic_cast<B *>(&p))
		std::cout << "p: " << getName<B>() << std::endl;
	else if (dynamic_cast<B *>(&p))
		std ::cout << "p: " << getName<C>() << std::endl;
}

template <>
std::string getName<A>() { return "A"; }
template <>
std::string getName<B>() { return "B"; }
template <>
std::string getName<C>() { return "C"; }