// my first C++ program
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main() {
	// ask for the person's name
	cout << "Please enter the person's name: ";
	string name;
	cin >> name;
	cout << std::endl;
	const string greeting = "Hello, " + name + "!";

	// get pad size
	cout << "Determine padding size: ";
	int pad;
	cin >> pad;
	cout << std::endl;
	const int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;

	// write message
	for (int r = 0; r != rows; ++r) {
		int c = 0;
		while (c != cols) {
			if (r == 0 || r == rows-1 || c == 0 || c == cols-1) {
				cout << "*";
				c++;
			} else {
				if (r == pad+1 && c == pad+1) {
					cout << greeting;
					c = c + greeting.size();
				} else {
					const string::size_type num_spaces = (r != pad + 1) ? cols-2 : pad;
					const string spaces(num_spaces, ' ');		
					cout << spaces;
					c += spaces.size();
				}
			}		
		}
		cout << std::endl;
		// invariant: we have written r rows of output thus far	
	}

	return 0;
}
