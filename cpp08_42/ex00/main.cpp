#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vector;
	std::vector<int>::iterator iterat;
	for (int i = 0; i < 100; i++)
		vector.push_back(i);

	std::cout << "Pushed back 100 elem on vector." << std::endl << std::endl;
	try
	{
		iterat = easyfind(vector, 15);
		std::cout << "iterat on easyfind vector for 15: " << *iterat << std::endl;
		iterat = easyfind(vector, 42);
		std::cout << "iterat on easyfind vector for 42: " << *iterat << std::endl;
		iterat = easyfind(vector, 66);
		std::cout << "iterat on easyfind vector for 66: " << *iterat << std::endl;
		iterat = easyfind(vector, 78);
		std::cout << "iterat on easyfind vector for 78: " << *iterat << std::endl;
		iterat = easyfind(vector, 90);
		std::cout << "iterat on easyfind vector for 90: " << *iterat << std::endl;
		iterat = easyfind(vector, 134);
		std::cout << "iterat on easyfind vector for 134 : " << *iterat << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << "Exception :  " << e.what() << std::endl;
	}
}