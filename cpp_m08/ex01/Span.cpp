#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N)
{
}

Span::Span(const Span &other)
{
	this->_numbers = other._numbers;
	this->_maxSize = other._maxSize;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_numbers = other._numbers;
		this->_maxSize = other._maxSize;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int nb)
{
	if (_numbers.size() >= _maxSize)
		throw std::out_of_range("Span is full");
	else
		_numbers.push_back(nb);
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span!");
	std::vector<int> copy = _numbers;
	std::sort(copy.begin(), copy.end());
	unsigned int min_diff = copy[1] - copy[0];
	for (size_t i = 1; i < _numbers.size(); i++)
	{
		unsigned int curr = copy[i] - copy[i - 1];
		if (curr < min_diff)
			min_diff = curr;
	}
	return min_diff;
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span!");
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	return max - min;
}
