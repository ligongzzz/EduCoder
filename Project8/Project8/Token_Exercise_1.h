#include "std_lib_facilities.h"
#include <map>

class Token {
	string str;
	int total_cnt = 0;
	class r_type {
	public:
		int cnt = 0;
		string out_str;
		r_type() = default;
		r_type(int cnt, string out_str) :cnt(cnt), out_str(out_str) {}
	};
	map<string, r_type> cnt_data;
	vector<r_type> ans_data;
	vector<string> dest_data;

public:
	Token() = default;
	void dest(const string& s);
	void add(const string& s);
	void find();
	void strcmp_sort();
	void print();
};
