#include <cctype>
#include <iostream>
#include <string>
#include <vector>

#include "stringops.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

int main() {
	string s;

	while(getline(cin, s)) {
		vector<string> words = split(s);
		for (vector<string>::const_iterator iter = words.begin(); 
			 iter != words.end(); iter++) {
			cout << (*iter) << endl;
		}
	}

	return 0;
}