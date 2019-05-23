#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;

int main() {

	// get student's name
	cout << "Please enter your name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	// get exam grades
	cout << "Enter your midterm grades and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	// get homework grades
	cout << "Enter your homework grades, followed by end-of-file: ";
	int count  = 0;
	double sum = 0;
	double x;
	while(cin >> x) {
		count++;
		sum += x;
		// invariant: we have read count grades
	}

	// compute student grades
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		 << 0.2 * midterm + 0.4 * final + 0.4 * sum / count 
		 << setprecision(prec) << endl;
}