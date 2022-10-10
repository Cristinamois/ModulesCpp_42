#include "whatever.hpp"

int main(void)
{
	int a = 42;
	int b = 43;
	::swap(a, b);
	std::cout << "a = " << a << " b = " << b << std::endl;
	std::cout << "min btwn a and b = " << ::min(a, b) << std::endl;
	std::cout << "mac btwn a and b = " << ::max(a, b) << std::endl;

	std::string s1 = "Lucifer";
	std::string s2 = "Cristina";
	std::cout << "s1 = " << s1 << " s2 = " << s2 << std::endl;
	std::cout << "min btwn s1 and s2 = " << ::min(s1, s2) << std::endl;
	std::cout << "max btwn s1 and s2 = " << ::max(s1, s2) << std::endl;

	return (0);  
}