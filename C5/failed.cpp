#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>

#include "grader.h"
#include "median.h"
#include "studentinfo.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::list;
using std::max;
using std::setprecision;
using std::sort;
using std::string;
using std::streamsize;

// lists are faster for deletion; vectors are faster for random and sequential access
list<StudentInfo> extract_fails(list<StudentInfo>& students) {
	list<StudentInfo> fail;
	list<StudentInfo>::const_iterator iter = students.begin();

	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else iter++;
	}

	return fail;
}

int main() {
	list<StudentInfo> students;
	StudentInfo record;
	string::size_type max_len = 0;

	// get student information
	while(read(cin, record)) {
		students.push_back(record);
		max_len = max(max_len, record.name.size());
	}
	students.sort(compare);

	// filter out failing students
	list<StudentInfo> failed = extract_fails(students);

	// compute final grade for each student
	for (list<StudentInfo>::const_iterator iter = students.begin(); 
		 iter != students.end(); iter++) {
		string name = iter->name;
		cout << name << string(max_len - name.size() + 1, ' ');

		try {
			double final_grade = grade(*iter);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		} catch(domain_error e) {
			cout << e.what() << endl;
		}
	}

	return 0;
}
