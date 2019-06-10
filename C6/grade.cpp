#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

#include "grader.h"
#include "median.h"
#include "studentinfo.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::ostream;
using std::string;
using std::vector;

void write_analysis(ostream& out, const string& name, 
					double analysis(const vector<StudentInfo>&), 
	                const vector<StudentInfo>& did, 
	                const vector<StudentInfo>& didnt) 
{
	out << name << endl 
	    << "Students who did all their homework: " << analysis(did) << endl
		<< "Students who didn't do all their homework: " << analysis(didnt) << endl;
}

int main() 
{
	// get student information
	vector<StudentInfo> did, didnt;
	StudentInfo record;
	while(read(cin, record)) {
		if (did_all_hw(record)) 
			did.push_back(record);
		else                    
			didnt.push_back(record);
	}

	// ensure analysis is meaningful
	if (did.empty()) {
		cout << "All students did not submit at least one homework." << endl;
		return 1;
	}
	if (didnt.empty()) {
		cout << "All students did all of their homeworks." << endl;
		return 1;
	}

	// perform analysis
	write_analysis(cout, "Median Analysis", median_analysis, did, didnt);
	write_analysis(cout, "Average Analysis", average_analysis, did, didnt);
	write_analysis(cout, "Optimistic Median Analysis", opt_median_analysis, did, didnt);
	return 0;
}
