#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::string;
using std::streamsize;
using std::vector;

typedef vector<double>::size_type vec_sz;

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
	vector<double> homework;
	double x;
	while(cin >> x) homework.push_back(x);

	// sort homework grades
	vec_sz size = homework.size();
	if (size == 0)  {
		cout << endl << "You must enter your homework grades. "
		                "Please try again." << endl;
		return 1;
	}
	sort(homework.begin(), homework.end());

	// compute median homework grade
	vec_sz mid = size / 2;
	double median;
	median = (size % 2 == 0) ? (homework[mid] + homework[mid-1]) / 2 : homework[mid];

	// compute student grades
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		 << 0.2 * midterm + 0.4 * final + 0.4 * median 
		 << setprecision(prec) << endl;
}
