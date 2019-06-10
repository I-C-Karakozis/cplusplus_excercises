#include "grader.h"

#include <stdexcept>

#include "median.h"

using std::domain_error;
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

// did a student fail?
bool fgrade(const StudentInfo& s) {
	return grade(s) < 60;
}


