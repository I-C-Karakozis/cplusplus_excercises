#ifndef GUARD_stringops_h
#define GUARD_stringops_h

#include <string>
#include <vector>

void print_string_vector (const std::vector<std::string>& v);
std::vector<std::string> split(const std::string& s);
std::string::size_type width(const std::vector<std::string>& v);
std::vector<std::string> frame(const std::vector<std::string>& v);

#endif
