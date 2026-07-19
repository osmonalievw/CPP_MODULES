#include <iostream>
#include "Span.hpp"
int main()
{
	{
		std::cout << "Testing the example from the PDF subject" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "\n--- Testing 10,000 numbers ---" << std::endl;
		Span hugeSpan(10000);
		std::vector<int> massiveVector;

		for (int i = 0; i < 10000; i++)
		{
			massiveVector.push_back(i * 2);
		}

		hugeSpan.addNumbers(massiveVector.begin(), massiveVector.end());

		std::cout << "Shortest: " << hugeSpan.shortestSpan() << std::endl;
		std::cout << "Longest:  " << hugeSpan.longestSpan() << std::endl;
	}
	return 0;
}
