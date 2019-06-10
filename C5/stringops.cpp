#include "stringops.h"

#include <algorithm>
#include <cctype>
#include <iostream>

using std::cout;
using std::endl;
using std::isspace;
using std::max;
using std::string;
using std::vector;

void print_string_vector (const vector<string>& v) {
	for (vector<string>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	cout << endl;
}

vector<string> split(const string& s) {
	vector<string> words;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		// ignore whitespaces
		while(i != s.size() && isspace(s[i])) i++;

		// collect word
		string_size j = i;
		while(j != s.size() && !(isspace(s[j]))) j++;

		// copy word
		if (i != j) {
			words.push_back(s.substr(i, j-i));
			i = j;
		}
	}

	return words;
}

string::size_type width(const vector<string>& v) {
	string::size_type max_width = 0;

	for (vector<string>::size_type i = 0; i < v.size(); i++)
		max_width = max(v[i].size(), max_width);

	return max_width;
}

vector<string> frame(const vector<string>& v) {
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border = string(maxlen + 4, '*');

	ret.push_back(border);
	print_string_vector(v);

	for (vector<string>::size_type i = 0; i < v.size(); ++i) {
		ret.push_back("* " + v[i]);//+ string(maxlen - v[i].size(), ' ') + " *");
	}

	ret.push_back(border);
	return ret;

}
