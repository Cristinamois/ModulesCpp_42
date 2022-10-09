#include <iostream>
#include <cstring>

int main(int ac, char **av)
{
	size_t	av_len;

	av_len = 0;
	if (ac > 1)
	{
		for (int rep = 1; rep < (ac); rep++)
		{
			av_len = std::strlen(av[rep]);
			for (size_t i = 0; i < av_len; i++)
			{
				av[rep][i] = std::toupper(av[rep][i]);
				std::cout << av[rep][i];
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE NOISE *" << std::endl;
		return (0);
	}
	// std::cout << std::endl;
	return (0);
}