#include "Array.hpp"
#include <iostream>


int main(void)
{
	Array<int>			intArray;
	Array<std::string>	stringArray(10);
	Array<std::string>	otherStringArray;
	stringArray[0] = "Hello";
	stringArray[1] = "lucifer";
	stringArray[2] = "cristina";
	stringArray[3] = "no creativity for strarr";
	stringArray[4] = "uhhhhhhhh";
	stringArray[5] = "gneugneugneu";
	std::cout << "intArray.size() = " << intArray.size() << std::endl;
	std::cout << "stringArray.size() = " << stringArray.size() << std::endl;
	otherStringArray = stringArray;
	otherStringArray[3] = "i'm out";

	std::cout << "strarray = " << stringArray[3] << std::endl;
	std::cout << "copystrarray[3] = " << otherStringArray[3] << std::endl;
	try
	{
		std::cout << stringArray[59] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << stringArray[-3] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;

}