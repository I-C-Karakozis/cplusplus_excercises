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

bool did_all_hw (const StudentInfo& s);

std::vector<StudentInfo> extract_fails(std::vector<StudentInfo>& students);

#endif
