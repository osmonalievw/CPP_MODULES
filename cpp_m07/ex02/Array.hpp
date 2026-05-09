#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>

template <typename T>
class Array
{
private:
	T *array;
	unsigned int length;

public:
	Array();
	Array(unsigned int n);
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array();

	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;
	unsigned int size() const;
	T *begin();
	T *end();
	const T *begin() const;
	const T *end() const;
};

#include "Array.tpp"

#endif