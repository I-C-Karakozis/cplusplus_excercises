#ifndef GUARD_studentinfo_h
#define GUARD_studentinfo_h

#include <iostream>
#include <string>
#include <vector>

struct StudentInfo {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
};

bool compare(const StudentInfo& a, const StudentInfo& b);
std::istream& read_hw(std::istream& in, std::vector<double>& hw);
std::istream& read(std::istream& in, StudentInfo& s);

#endif
