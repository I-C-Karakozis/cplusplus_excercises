#include "grader.h"

#include <algorithm>
#include <stdexcept>

#include "median.h"

using std::back_inserter;
using std::domain_error;
using std::transform;
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
bool fgrade(const StudentInfo& s) 
{
	return grade(s) < 60;
}

// did a student pass?
bool pgrade(const StudentInfo& s) 
{
	return !fgrade(s);
}

double grade_aux(const StudentInfo& s) 
{
	try {
		return grade(s);
	} catch (domain_error e) {
		return grade(s.midterm, s.final, 0);
	}
}

double median_analysis(const vector<StudentInfo>& v) 
{
	vector<double> grades;
	transform(v.begin(), v.end(), back_inserter(grades), grade_aux);
	return median(grades);
}

double average_grade(const StudentInfo& s) 
{
	return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const vector<StudentInfo>& v) 
{
	vector<double> grades;
	transform(v.begin(), v.end(), back_inserter(grades), average_grade);
	return median(grades);
}

double opt_median_grade(const StudentInfo& s) 
{
	vector<double> non_zero;
	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(non_zero), 0.0);

	if (non_zero.empty()) 
		return grade(s.midterm, s.final, 0);
	else
		return grade(s.midterm, s.final, median(non_zero));
}

double opt_median_analysis(const vector<StudentInfo>& v) 
{
	vector<double> grades;
	transform(v.begin(), v.end(), back_inserter(grades), opt_median_grade);
	return median(grades);
}

