#include "iter.hpp"
#include <iostream>
#include <cctype>

void ft_tolower(char &arr)
{
	arr = std::tolower(static_cast<unsigned char>(arr));
}

void ft_toupper(char &arr)
{
	arr = std::toupper(static_cast<unsigned char>(arr));
}

int main()
{
	// char
	{
		std::cout << "char: {" << std::endl;
		char ch[] = {'A', 'B', 'D'};
		::iter(ch, 3, some_func<char>);
		std::cout << "}" << std::endl;
	}
	// int, double, float
	{
		std::cout << "int: {" << std::endl;
		int a[] = {0, 3, 43};
		::iter(a, 3, some_func<int>);
		std::cout << "}" << std::endl;
		std::cout << "double: {" << std::endl;
		double b[] = {0.0, 3.3, 43.43};
		::iter(b, 3, some_func<double>);
		std::cout << "}" << std::endl;
		std::cout << "float: {" << std::endl;
		float c[] = {0.1, 3.4, 43.44};
		::iter(c, 3, some_func<float>);
		std::cout << "}" << std::endl;
	}
	// string
	{
		std::cout << "string: {" << std::endl;
		std::string word[] = {"Hello", "World", "!"};
		::iter(word, 3, some_func<std::string>);
		std::cout << "}" << std::endl;
	}
}