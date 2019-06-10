#include <algorithm>
#include <stdexcept>
#include <vector>

using std::domain_error;
using std::sort;
using std::vector;

typedef vector<double>::size_type vec_sz;

// vec passed by value
double median(vector<double> vec) {
	// sort the vector
	vec_sz size = vec.size();
	if (size == 0) throw domain_error("median of an empty vector");
	sort(vec.begin(), vec.end());

	// find median
	vec_sz mid = size / 2;
	return (size % 2 == 0) ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}
