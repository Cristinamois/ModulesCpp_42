#include "Convertor.hpp"

static bool	isValidToInt(double nbr)
{
	return (nbr <= std::numeric_limits<int>::max()
			&& nbr >= std::numeric_limits<int>::min()
			&& nbr != std::numeric_limits<double>::infinity()
			&& nbr != -std::numeric_limits<double>::infinity()
			&& nbr != std::numeric_limits<double>::quiet_NaN());
}
static bool	isValidToFloat(double nbr)
{
	return ((nbr <= std::numeric_limits<float>::max()
			 && nbr >= -std::numeric_limits<float>::max())
			|| nbr == std::numeric_limits<double>::infinity()
			|| nbr == -std::numeric_limits<double>::infinity()
			|| std::isnan(nbr));
}

Convertor::Convertor(std::string input): _arg(input), _type("-") {
	this->_intVal = 0;
	this->_charVal = 0;
	this->_floatVal = 0;
	this->_doubleVal = 0;
	if (!this->parseArg())
		throw (Convertor::notGoodArgException());
	std::cout << "type: " << this->_type << std::endl;
	if (this->_type == "c") {
		this->_intVal = static_cast<int>(input[0]);
		this->_charVal = static_cast<char>(input[0]);
		this->_floatVal = static_cast<float>(input[0]);
		this->_doubleVal = static_cast<double>(input[0]);
	}
	if (this->_type == "i") {
		this->_intVal = static_cast<int>(atoi(input.c_str()));
		this->_charVal = static_cast<char>(atoi(input.c_str()));
		this->_floatVal = static_cast<float>(atoi(input.c_str()));
		this->_doubleVal = static_cast<double>(atoi(input.c_str()));
	}
	if (this->_type == "d") {
		this->_intVal = static_cast<int>(atof(input.c_str()));
		this->_charVal = static_cast<char>(atof(input.c_str()));
		this->_floatVal = static_cast<float>(atof(input.c_str()));
		this->_doubleVal = static_cast<double>(atof(input.c_str()));
	}
	if (this->_type == "f") {
		this->_intVal = static_cast<int>(atof(input.c_str()));
		this->_charVal = static_cast<char>(atof(input.c_str()));
		this->_floatVal = static_cast<float>(atof(input.c_str()));
		this->_doubleVal = static_cast<double>(atof(input.c_str()));
	}
}

Convertor::Convertor(const Convertor &src): _arg(src._arg) {
	*this = src;
}

Convertor &Convertor::operator=(const Convertor &src) {
	this->_intVal = src._intVal;
	this->_charVal = src._charVal;
	this->_floatVal = src._floatVal;
	this->_doubleVal = src._doubleVal;
	return *this;
}

Convertor::~Convertor() {}

bool Convertor::yonkoPars() {
	if (this->_arg == "inf" || this->_arg == "+inf" || this->_arg == "-inf" || this->_arg == "nan")
		this->_type = "d";
	else if (this->_arg == "inff" || this->_arg == "+inff" || this->_arg == "-inff" || this->_arg == "nanf")
		this->_type = "f";
	return this->_type != "-";
}

bool Convertor::parseArg() {
	if (!this->_arg.length())
		return false;
	if (yonkoPars())
		return true;
	if (this->_type != "-")
		return true;
	if (this->_arg.length() == 1)
		this->_type = "c";
	if (std::isdigit(this->_arg[0]) || this->_arg[0] == '-' || this->_arg[0] == '+' || this->_arg[0] == '.')
	{
		int i = this->_arg[0] == '-';
		int dotQty = 0;

		if (this->_arg[i + 1] && this->_arg[i] == '.' && this->_arg[i + 1] == 'f')
			return false;
		while (this->_arg[i] == '.' || std::isdigit(this->_arg[i])) {
			if (this->_arg[i] == '.')
				dotQty++;
			if (dotQty > 1)
				return false;
			i++;
		}
		if (!this->_arg[i]) {
			this->_type = dotQty == 1 ? 'd' : 'i';
		} else if (this->_arg[i] == 'f') {
			this->_type = this->_arg[i + 1] == 0 ? 'f' : '-';
		}
	}
	if (this->_type == "-")
		return false;
	return true;
}

void Convertor::printTypes() {
	this->_putChar();
	this->_putNbr();
	this->_putFloat();
	this->_putDouble();
}

void Convertor::_putChar() {
	if (this->_doubleVal > 127 || this->_doubleVal < 0 || isnan(this->_doubleVal))
		std::cout << "char   : Impossible" << std::endl;
	else if (this->_charVal < 127 && this->_charVal > 31)
		std::cout << "char   : " << this->_charVal << std::endl;
	else
		std::cout << "char   : Not displayable" << std::endl;
}

void Convertor::_putNbr() {
	if (isValidToInt(this->_doubleVal))
		std::cout << "int    : " << this->_intVal << std::endl;
	else
		std::cout << "int    : Impossible" << std::endl;
}

void Convertor::_putFloat() {
	if (!isValidToFloat(this->_doubleVal))
		std::cout << "float  : Impossible" << std::endl;
	else {
		if (this->_doubleVal - static_cast<int>(this->_doubleVal/1.0) * 1.0 == 0.0)
			std::cout << "float  : " << this->_floatVal << ".0f" << std::endl;
		else
			std::cout << "float  : " << this->_floatVal << "f" << std::endl;
	}
}

void Convertor::_putDouble() {
	if (this->_doubleVal - static_cast<int>(this->_doubleVal/1.0) * 1.0 == 0.0)
		std::cout << "double : " << this->_floatVal << ".0" << std::endl;
	else
		std::cout << "double : " << this->_floatVal << std::endl;
}
