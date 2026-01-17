#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		this->materias[i] = 0;
	}
	// std::cout << "[MateriaSource] Default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.materias[i])
			this->materias[i] = other.materias[i]->clone();
		else
			this->materias[i] = NULL;
	}
	// std::cout << "[MateriaSource] Copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->materias[i])
				delete this->materias[i];
			this->materias[i] = NULL;
		}
		for (int i = 0; i < 4; i++)
		{
			if (other.materias[i])
				this->materias[i] = other.materias[i]->clone();
			else
				this->materias[i] = NULL;
		}
	}
	//	std::cout << "[MateriaSource] Copy assignment operator called" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i])
			delete this->materias[i];
	}
	// std::cout << "[MateriaSource] Destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i] == NULL)
		{
			this->materias[i] = m;
			// std::cout << "[MateriaSource] Learned " << m->getType() << std::endl;
			return;
		}
	}
	delete m;
	// std::cout << "[MateriaSource] Source is full, materia deleted" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i] != NULL && this->materias[i]->getType() == type)
			return this->materias[i]->clone();
	}
	return (0);
}