#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack &operator=(const MutantStack &other);
	~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iter;
	typedef typename std::stack<T>::container_type::reverse_iterator riter;

	iter begin();
	iter end();
	riter rbegin();
	riter rend();
};

#include "MutantStack.tpp"

#endif