#include "stringops.h"

#include <algorithm>
#include <cctype>
#include <iostream>

using std::cout;
using std::endl;
using std::equal;
using std::find;
using std::find_if;
using std::isalnum;
using std::isspace;
using std::max;
using std::string;
using std::vector;

typedef string::const_iterator const_iter;

void print_string_vector (const vector<string>& v) {
	for (vector<string>::size_type i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	cout << endl;
}

bool space(char c) {
	return isspace(c);
}

bool not_space(char c) {
	return !isspace(c);
}

vector<string> split(const string& s) {
	vector<string> words;

	const_iter i = s.begin();
	while (i != s.end()) {
		// ignore whitespaces
		i = find_if(i, s.end(), not_space);

		// collect word
		const_iter j = find_if(i, s.end(), space);

		// copy word
		if (i != j)	words.push_back(string(i, j));
		i = j;
	}

	return words;
}

bool is_palindrome(string s) 
{
	return equal(s.begin(), s.end(), s.rbegin());
}

bool not_url_char(char c) 
{
	static const string url_ch = "~;/?:@=&$-_.+'(),";
	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

const_iter url_end(const_iter b, const_iter e) {
	return find_if(b, e, not_url_char);
}

const_iter url_begin(const_iter b, const_iter e) {
	// left as an excercise
}

vector<string> find_urls(const string s)
{
	vector<string> urls;
	const_iter b = s.begin, e = s.end();

	while (b != e) {
		// find url
		b = url_beg(b, e);

		// copy url
		if (b != e) {
			const_iter after = url_end(b, e);
			urls.push_back(string(b, after));
			b = after;
		}
	}

	return urls
}
