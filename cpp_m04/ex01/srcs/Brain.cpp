#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	std::cout << "Copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	std::cout << "Copy assignment operator called." << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Default Brain destructor called" << std::endl;
}

const std::string &Brain::getIdea(size_t index) const
{
	if (index >= 0 && index < 100)
		return this->ideas[index];
	return this->ideas[0];
}

void Brain::setIdea(size_t index, std::string idea)
{
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
	else
		std::cout << "Error: Index out of bounds (0-99 only)" << std::endl;
}