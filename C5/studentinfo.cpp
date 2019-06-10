#include "studentinfo.h"

using std::istream;
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
