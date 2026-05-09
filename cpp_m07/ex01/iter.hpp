#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
void some_func(T &val)
{
	std::cout << val << std::endl;
}

template <typename A, typename T>
void iter(A *adressArray, const size_t length, T func)
{
	if (!adressArray)
		return;
	for (size_t i = 0; i < length; i++)
		func(adressArray[i]);
}

#endif