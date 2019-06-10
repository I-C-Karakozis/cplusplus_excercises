#include <cctype>
#include <iostream>
#include <string>
#include <vector>

#include "stringops.h"

using std::cin;
using std::getline;
using std::string;
using std::vector;

int main() {
	string s;
	vector<string> words;
	while(getline(cin, s)) words.push_back(s);

	print_string_vector(words);
	vector<string> framed_words = frame(words);
	print_string_vector(framed_words);

	return 0;
}