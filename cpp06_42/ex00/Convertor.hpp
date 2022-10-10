#ifndef CONVERTOR_HPP
#define CONVERTOR_HPP

#include <string>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <limits>
#include <cmath>

class Convertor {
public:
	Convertor(std::string arg);
	Convertor(const Convertor &src);
	Convertor &operator=(const Convertor &src);
	~Convertor();

	class notGoodArgException: public std::exception {
		virtual const char* what() const throw()
		{
			return "Arg is not valid.";
		}
	};

	void printTypes();

private:
	void _putChar();
	void _putNbr();
	void _putFloat();
	void _putDouble();

	bool parseArg();
	bool yonkoPars();

	const std::string _arg;
	std::string _type;

	int _intVal;
	char _charVal;
	float _floatVal;
	double _doubleVal;
};

#endif
