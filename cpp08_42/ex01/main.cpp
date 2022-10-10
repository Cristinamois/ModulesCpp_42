#include "Span.hpp"

int	main( void )
{
	srand(time(NULL));

	Span	span1(6);
	span1.addNumber(4);
	span1.addNumber(7);
	span1.addNumber(2);
	span1.addNumber(6);
	span1.addNumber(25);
	try
	{
		span1.addNumber(4);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "[test1] Shortest: " << span1.shortestSpan() << std::endl;
	std::cout << "[test1] Longest: " << span1.longestSpan() << std::endl;
	std::cout << std::endl;


	Span	span2(50000);
	span2.addNumber(3);
	span2.randomFiller();
	std::cout << "[test2] Shortest: " << span2.shortestSpan() << std::endl;
	std::cout << "[test2] Longest: " << span2.longestSpan() << std::endl;
	std::cout << std::endl;


	Span				span3(5);
	std::vector<int>	vect;
	vect.push_back(25);
	vect.push_back(5);
	vect.push_back(12);
	vect.push_back(90);
	vect.push_back(-2);
	span3.iteratorFiller(vect.begin(), vect.end());
	std::cout << "[test3] Shortest: " << span3.shortestSpan() << std::endl;
	std::cout << "[test4] Longest: " << span3.longestSpan() << std::endl;

	return 0;
}