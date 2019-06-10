#include "studentinfo.h"

#include <algorithm>

#include "grader.h"

using std::back_inserter;
using std::find;
using std::istream;
using std::remove_if;
using std::remove_copy_if;
using std::vector;

bool compare(const StudentInfo& a, const StudentInfo& b) {
	return a.name < b.name;
}

// read homework from input stream in to hw vector
istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		double x;
		hw.clear();
		while(in >> x) hw.push_back(x);
		in.clear();
	}

	return in;
}

// read student information
istream& read(istream& in, StudentInfo& s) {
	in >> s.name >> s.midterm >> s.final;
	read_hw(in, s.homework);
	return in;
}

bool did_all_hw (const StudentInfo& s) {
	return (find(s.homework.begin(), s.homework.end(), 0) == s.homework.end());
}

vector<StudentInfo> extract_fails(vector<StudentInfo>& students) {
	vector<StudentInfo> fail;

	remove_copy_if(students.begin(), students.end(), back_inserter(fail), pgrade);
	students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());

	return fail;
}
