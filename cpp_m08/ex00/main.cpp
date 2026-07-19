#include "easyfind.hpp"

int main()
{
	std::list<int> weights;

	weights.push_back(10);
	weights.push_back(20);
	weights.push_back(22);
	weights.push_back(40);

	try
	{
		std::list<int>::const_iterator res = easyfind(weights, 22);
		std::cout << "Finded: " << *res << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::list<int>::const_iterator res = easyfind(weights, 54);
		std::cout << "Finded: " << *res << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::list<int>::const_iterator res = easyfind(weights, 2147483647);
		std::cout << "Finded: " << *res << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}