#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <stdexcept>
#include <list>
#include <algorithm>

template <typename T>

typename T::const_iterator easyfind(const T &list, int val)
{
	typename T::const_iterator curr = std::find(list.begin(), list.end(), val);

	if (curr != list.end())
		return curr;
	else
		throw std::runtime_error("Error: Target value not found.");
}

#endif