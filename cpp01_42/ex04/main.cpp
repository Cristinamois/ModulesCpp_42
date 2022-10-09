

#include <iostream>
#include <string>
#include <fstream>



std::string ft_replace(std::string line, std::string r_this, std::string r_with)
{
	int start = line.find(r_this);
	if (start != -1)
	{
		line.erase(start, r_this.length());
		line.insert(start, r_with);
	}
	return (line);
}

int isEmpty(std::string s1, std::string s2)
{
	if (s1.empty())
	{
		std::cout << "ERROR: s1 can not be empty!" << std::endl;
		return (1);
	}
	else if (s2.empty())
	{
		std::cout << "ERROR: s2 can not be empty!" << std::endl;
		return (1);
	}
	return (0);
}

int main(int ac, char **av)
{
	std::string line;
	std::ifstream file(av[1], std::fstream::in);
    bool opening;

    opening = file.is_open();
	if (ac != 4)
	{
		std::cout << "Error Args\n";
		return (1);
	}
	if (opening == true)
	{
		const std::string fileName(av[1]);
		if (isEmpty(av[2], av[3]))
			return (1);
		std::ofstream destination((fileName + ".replace").c_str());
		while (getline(file, line))
		{
			line = ft_replace(line, av[2], av[3]);
			destination << line << std::endl;
		}
	}
	else
		std::cout << "Error in open file " << std::endl;
	return (0);
}