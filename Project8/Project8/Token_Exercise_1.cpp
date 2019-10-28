#include "std_lib_facilities.h"
#include "Token_Exercise_1.h"
#include <cstring>

void Token::add(const string& s) {
	str = s;
}

void Token::dest(const string& s) {
	int length = s.length();
	for (int i = 0, j = 0; j <= length; ++j) {
		if (s[j] == ' ' || j == length) {
			string sub_str = s.substr(i, j - i);
			dest_data.emplace_back(sub_str);
			i = j + 1;
		}
	}
}

void Token::find() {
	int length = str.length();
	for (int i = 0, j = 0; j <= length; ++j) {
		if (!((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z')
			|| str[j] >= '0' && str[j] <= '9') && str[j] != '_' && str[j] != '-') {
			string str_sub = str.substr(i, j - i);
			i = j + 1;
			//Check if no letters.
			bool flag = false;
			for (int k = 0; k < str_sub.length(); ++k) {
				if ((str_sub[k] >= 'a' && str_sub[k] <= 'z') || (str_sub[k] >= 'A' && str_sub[k] <= 'Z')
					|| str_sub[k] >= '0' && str_sub[k] <= '9') {
					flag = true;
					break;
				}
			}
			if (!flag)
				continue;
			if (str_sub.length() == 0)
				continue;
			string sub_index = str_sub;
			for (auto& p : sub_index)
				if (p >= 'A' && p <= 'Z')
					p = 'a' + p - 'A';
			if (cnt_data.find(sub_index) == cnt_data.end()) {
				cnt_data.insert(make_pair(sub_index, r_type(1, str_sub)));
			}
			else {
				cnt_data[sub_index].cnt++;
				if (strcmp(str_sub.c_str(), cnt_data[sub_index].out_str.c_str()) > 0) {
					cnt_data[sub_index].out_str = str_sub;
				}
			}
			++total_cnt;
		}
	}
}

void Token::strcmp_sort() {
	ans_data.clear();
	for (auto& p : cnt_data)
		ans_data.emplace_back(p.second);
	sort(ans_data.begin(), ans_data.end(), [](r_type& a, r_type& b) {
		return a.cnt > b.cnt || (a.cnt == b.cnt && strcmp(a.out_str.c_str(), b.out_str.c_str()) < 0);
		});
	if (ans_data.size() > 5)
		ans_data.erase(ans_data.begin() + 5, ans_data.end());
	/*
	sort(ans_data.begin(), ans_data.end(), [](r_type& a, r_type& b) {
		return strcmp(a.out_str.c_str(), b.out_str.c_str()) < 0;
		});*/
}

void Token::print() {
	cout << total_cnt << endl;
	bool fi = true;
	for (auto& p : ans_data) {
		if (fi)
			fi = false;
		else
			cout << " ";
		std::cout << "(" << p.out_str << "," << p.cnt << ")";
	}
	cout << endl;
	fi = true;
	for (auto p : dest_data) {
		if (fi)
			fi = false;
		else
			cout << " ";
		cout << "(" << p << ",";
		for (auto& t : p)
			if (t >= 'A' && t <= 'Z')
				t = 'a' + t - 'A';
		if (cnt_data.find(p) != cnt_data.end()) {
			cout << cnt_data[p].cnt;
		}
		else
			cout << 0;
		cout << ")";
	}
}