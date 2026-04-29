#include "Array.hpp"

int main()
{
	Array<int> first(5);
	// Array<int> second(7);

	for (size_t i = 0; i < first.size(); i++)
	{
		first[i] = i * 3;
		std::cout << first[i] << std::endl;
	}
	first[4] = 20;
	std::cout << first[4] << std::endl;
	std::cout << first.begin() << std::endl;
}