#include <iostream>
#include <string>
#include "whatever.hpp" // Ensure swap, min, and max are defined here

class Awesome
{
private:
	int _n;
	std::string _name;

public:
	Awesome(int n, std::string name) : _n(n), _name(name) {}

	bool operator==(Awesome const &rhs) const { return (this->_n == rhs._n); }
	bool operator!=(Awesome const &rhs) const { return (this->_n != rhs._n); }
	bool operator>(Awesome const &rhs) const { return (this->_n > rhs._n); }
	bool operator<(Awesome const &rhs) const { return (this->_n < rhs._n); }
	bool operator>=(Awesome const &rhs) const { return (this->_n >= rhs._n); }
	bool operator<=(Awesome const &rhs) const { return (this->_n <= rhs._n); }

	int get_n() const { return _n; }
	std::string get_name() const { return _name; }
};

int main()
{

	Awesome a(10, "A");
	Awesome b(20, "B");
	Awesome c(10, "C"); // Same value as 'a' (10) to test equality rule

	std::cout << "--- Testing Swap ---" << std::endl;
	std::cout << "Before: a=" << a.get_name() << "(" << a.get_n() << "), b=" << b.get_name() << "(" << b.get_n() << ")" << std::endl;
	::swap(a, b);
	std::cout << "After:  a=" << a.get_name() << "(" << a.get_n() << "), b=" << b.get_name() << "(" << b.get_n() << ")" << std::endl;

	std::cout << "\n--- Testing Min (Return second if equal) ---" << std::endl;
	// Comparing b(20) and a(10) -> should return a
	std::cout << "Min of 20 and 10: " << ::min(b, a).get_name() << std::endl;
	// Comparing a(10) and c(10) -> should return c (the second one)
	std::cout << "Min of 10 and 10: " << ::min(a, c).get_name() << " (Expected: C_obj)" << std::endl;

	std::cout << "\n--- Testing Max (Return second if equal) ---" << std::endl;
	// Comparing a(10) and b(20) -> should return b
	std::cout << "Max of 10 and 20: " << ::max(a, b).get_name() << std::endl;
	// Comparing a(10) and c(10) -> should return c (the second one)
	std::cout << "Max of 10 and 10: " << ::max(b, c).get_name() << " (Expected: C_obj)" << std::endl;

	return 0;
}
