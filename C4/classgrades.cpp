#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "median.h"
#include "studentinfo.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::max;
using std::setprecision;
using std::sort;
using std::string;
using std::streamsize;
using std::vector;

// compute final grade
double grade(double midterm, double final, double homework) {
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// grading policy
double grade(double midterm, double final, const vector<double>& hw) {
	if (hw.size() == 0) throw domain_error("submitted no homework grades");
	return grade(midterm, final, median(hw));
}

// compute final grade
double grade(const StudentInfo& s) {
	return grade(s.midterm, s.final, s.homework);
}

int main() {
	vector<StudentInfo> students;
	StudentInfo record;
	string::size_type max_len = 0;

	// get student information
	while(read(cin, record)) {
		students.push_back(record);
		max_len = max(max_len, record.name.size());
	}
	sort(students.begin(), students.end(), compare);

	// compute final grade for each student
	for (vector<StudentInfo>::size_type i = 0; i < students.size(); i++) {
		string name = students[i].name;
		cout << name << string(max_len - name.size() + 1, ' ');

		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		} catch(domain_error e) {
			cout << e.what() << endl;
		}
	}

	return 0;
}
