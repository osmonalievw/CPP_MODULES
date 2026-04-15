#include "Base.hpp"

int main(void)
{
	Base *base = Base::generate();
	std::cout << "Pointer identify: ";
	Base::identify(base);
	std::cout << "Reference identify: ";
	Base::identify(*base);
}