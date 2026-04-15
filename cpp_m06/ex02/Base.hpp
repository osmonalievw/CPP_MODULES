#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <string>

class A;
class B;
class C;

template <typename T>
std::string getName();

template <>
std::string getName<A>();
template <>
std::string getName<B>();
template <>
std::string getName<C>();

class Base
{
public:
	virtual ~Base();

	static Base *generate(void);
	static void identify(Base *p);
	static void identify(Base &p);
};

class A : public Base
{
};
class B : public Base
{
};
class C : public Base
{
};

#endif