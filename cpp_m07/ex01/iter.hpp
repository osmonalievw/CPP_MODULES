#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
void some_func(T &val)
{
	std::cout << val << std::endl;
}

template <typename A>
void iter(A *adressArray, size_t length, void (*func)(A &))
{
	if (!adressArray || !func)
		return;
	for (size_t i = 0; i < length; i++)
		func(adressArray[i]);
}

#endif