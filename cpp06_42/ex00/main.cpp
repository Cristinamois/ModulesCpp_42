#include "Convertor.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Invalid arg" << std::endl;
		return 0;
	}

	try {
		Convertor conv(argv[1]);

		conv.printTypes();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}