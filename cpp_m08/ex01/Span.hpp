#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>

class Span
{
private:
	unsigned int _maxSize;
	std::vector<int> _numbers;

public:
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	template <typename T>
	void addNumbers(T begin, T end)
	{
		int size = std::distance(begin, end);
		if (_numbers.size() + size > _maxSize)
			throw std::out_of_range("Not enough space to add all these numbers!");
		_numbers.insert(_numbers.end(), begin, end);
	}

	void
	addNumber(int nb);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
};

#endif