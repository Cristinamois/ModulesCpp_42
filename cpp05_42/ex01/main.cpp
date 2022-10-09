#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	try {
		Form form1("FORM1", 5, 1);
		std::cout << form1 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Form form2("FORM2", 1, 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Form form3("FORM3", 65, 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Form form4("FORM4", 149, 1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat Cristina = Bureaucrat("Criss Cross", 1);
		Form form5("FORM5", 150, 150);
		std::cout << form5 << std::endl;
		Cristina.signForm(form5);
		std::cout << form5 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat Lucifer = Bureaucrat("Lucifer", 10);
		Form form6("FORM6", 1, 1);
		std::cout << form6 << std::endl;
		Lucifer.signForm(form6);
		std::cout << form6 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}