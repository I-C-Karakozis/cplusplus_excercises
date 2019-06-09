#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::setprecision;
using std::sort;
using std::string;
using std::streamsize;
using std::vector;

typedef vector<double>::size_type vec_sz;

// vec passed by value
double median(vector<double> vec) {
	// sort the vector
	vec_sz size = vec.size();
	if (size == 0) throw domain_error("median of an empty vector");
	sort(vec.begin(), vec.end());

	// find median
	vec_sz mid = size / 2;
	return (size % 2 == 0) ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

// read homework from input stream in to hw vector
istream& read_hw(istream& in, vector<double>& hw) {
	cout << "Enter your homework grades, followed by end-of-file: ";

	if (in) {
		double x;
		hw.clear();
		while(in >> x) hw.push_back(x);
		in.clear();
	}

	return in;
}

// compute final grade
double grade(double midterm, double final, double homework) {
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// grading policy
double grade(double midterm, double final, const vector<double>& hw) {
	if (hw.size() == 0) throw domain_error("Student submitted no homework grades.");
	return grade(midterm, final, median(hw));
}

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
	vector<double> homework;
	read_hw(cin, homework);

	// compute student grades
	try {
		double final_grade = grade(midterm, final, homework);
		streamsize prec = cout.precision();
		cout << "Your final grade is " << setprecision(3)
			 << final_grade << setprecision(prec) << endl;
	} catch(domain_error) {
		cout << endl << "You must enter your homework grades. "
		                "Please try again." << endl;
		return 1;
	}

	return 0;
}
