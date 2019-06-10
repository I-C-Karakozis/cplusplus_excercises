#ifndef GUARD_grader_h
#define GUARD_grader_h

#include <vector>

#include "studentinfo.h"

double grade(double midterm, double final, double homework);

double grade(double midterm, double final, const std::vector<double>& hw);

double grade(const StudentInfo& s);

bool fgrade(const StudentInfo& s);

#endif
