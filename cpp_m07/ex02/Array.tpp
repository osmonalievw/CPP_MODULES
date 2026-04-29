#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array() : array(nullptr), length(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]()), length(n)
{
}

template <typename T>
Array<T>::Array(const Array<T> &other) : array(new T[other.length]()), length(other.length)
{
	for (size_t i = 0; i < length; i++)
		array[i] = other.array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete[] array;
		length = other.length;
		array = new T[other.length]();
		for (size_t i = 0; i < length; i++)
			array[i] = other.array[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] array;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= length)
		throw std::out_of_range("Index out of bounds");
	return array[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= length)
		throw std::out_of_range("Index out of bounds");
	return array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return length;
}

template <typename T>
T *Array<T>::begin()
{
	return array;
}

template <typename T>
T *Array<T>::end()
{
	return (array + length);
}

template <typename T>
const T *Array<T>::begin() const { return array; }

template <typename T>
const T *Array<T>::end() const { return array + length; }

#endif