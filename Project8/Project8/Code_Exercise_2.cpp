#include "Code_Exercise_2.h"
#include "std_lib_facilities.h"
#include <cstring>
#include <set>

void Code::add(const string& s) {
	auto ns = s;
	if (ns.find("//") != ns.npos) {
		ns.erase(ns.find("//"));
	}
	if(!ns.empty())
		str += ns + ' ';
}

void Code::parse() {
	// Erase the comment.
	while (true) {
		auto pos = str.find("/*");
		if (pos == string::npos) {
			break;
		}
		auto pos2 = str.find("*/", pos + 2);
		str.erase(pos, pos2 - pos + 2);
	}

	while (true) {
		auto pos = str.find("\\n");
		if (pos == string::npos) {
			break;
		}
		str[pos + 1] = ' ';
	}
	//cout << str << endl;

	int length = str.length();
	for (int i = 0, j = 0; j <= length; ++j) {
		if (!((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z')
			|| str[j] >= '0' && str[j] <= '9') && str[j] != '_') {
			string str_sub = str.substr(i, j - i);
			i = j + 1;
			if (str_sub.length() == 0)
				continue;
			/*
			if (str_sub[0] >= '0' && str_sub[0] <= '9')
				continue;*/
			if (word_list.find(str_sub) == word_list.end()) {
				ans_set.insert(str_sub);
			}
		}
	}

	for (auto p : ans_set)
		ans_list.emplace_back(p);
	// Sort
	sort(ans_list.begin(), ans_list.end(), [](string& a, string& b) {
		return strcmp(a.c_str(), b.c_str()) < 0;
		});
}

void Code::print() {
	bool fi = true;
	for (auto p : ans_list) {
		if (fi)
			fi = false;
		else
			cout << " ";
		cout << p;
	}
}