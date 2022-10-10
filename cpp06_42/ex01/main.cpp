#include "main.hpp"

uintptr_t serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

int main() {
	Data *data = new Data;
	uintptr_t raw;

	data->_int = 42;
	data->_float = 42.42f;
	data->_double = 420.667;
	data->_str = "Cristina is incroyable ok ?";


	std::cout << "Stored int    : " << data->_int << std::endl;
	std::cout << "Stored double : " << data->_double << std::endl;
	std::cout << "Stored float  : " << data->_float << std::endl;
	std::cout << "Stored string : " << data->_str << std::endl;


	raw = serialize(data);
	std::cout << "Serialized Data * to uintptr_t : " << raw << std::endl;
	data = NULL;

	std::cout << "Part 2->" << std::endl;
	data = deserialize(raw);
	std::cout << "Deserialized uintptr_t to Data *! " << std::endl;


	std::cout << "Stored int    : " << data->_int << std::endl;
	std::cout << "Stored double : " << data->_double << std::endl;
	std::cout << "Stored float  : " << data->_float << std::endl;
	std::cout << "Stored string : " << data->_str << std::endl;
}
