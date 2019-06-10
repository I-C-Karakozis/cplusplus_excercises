#ifndef GUARD_grader_h
#define GUARD_grader_h

#include <vector>

#include "studentinfo.h"

double grade(double midterm, double final, double homework);

double grade(double midterm, double final, const std::vector<double>& hw);

double grade(const StudentInfo& s);

bool fgrade(const StudentInfo& s);

bool pgrade(const StudentInfo& s);

double median_analysis(const std::vector<StudentInfo>& v);

double average_analysis(const std::vector<StudentInfo>& v);

double opt_median_analysis(const std::vector<StudentInfo>& v) ;

#endif
