// my first C++ program
#include <iostream>
#include <string>

int main() {
	// ask for the person's name
	std::cout << "Please enter the person's name: ";
	std::string name;
	std::cin >> name;

	// prepare fancy name output
	const std::string greeting = "* Hello, " + name + "! *";
	const std::string spaces(greeting.size() - 2, ' ');
	const std::string second = "*" + spaces + "*";
	const std::string first(greeting.size(), '*');

	// write message
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << greeting << std::endl;
	std::cout << second << std::endl;
	std::cout << first << std::endl;

	return 0;
}
