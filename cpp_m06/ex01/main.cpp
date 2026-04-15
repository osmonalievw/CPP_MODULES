#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	Data b;
	b.id = 424;
	b.name = "Razak";

	Data *orig = &b;

	uintptr_t res = Serializer::serialize(orig);
	Data *des = Serializer::deserialize(res);

	std::cout << std::hex << "original adress: " << orig << std::endl;
	std::cout << std::hex << "serialize adress: " << res << std::endl;
	std::cout << std::hex << "deserialize adress: " << des << std::endl;

	if (orig == des)
		std::cout
				<< "succes" << std::endl;
	else
		return (1);
	return (0);
}