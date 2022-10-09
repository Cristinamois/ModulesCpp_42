# include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat Cristina("Cristina", 1);
		Bureaucrat Lucifer("Lucifer", 43);

		Bureaucrat Foo("Foo", 150);

		std::cout << Cristina << std::endl;
		std::cout << Lucifer << std::endl;
		std::cout << Foo << std::endl;

		Cristina.elevation();
		Lucifer.elevation();
		Foo.diminution();
	
		std::cout << Cristina << std::endl;
		std::cout << Lucifer << std::endl;
		std::cout << Foo << std::endl;
	} catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}
}