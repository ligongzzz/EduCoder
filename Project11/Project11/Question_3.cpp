#include "std_lib_facilities.h"
#include "Question_3.h"
#include <iostream>

string str1, str2;
vector<vector<string>> dp_data;
string dp(int i, int j) {
	if (i == 0 || j == 0) {
		return "";
	}
	if (!dp_data[i][j].empty()) {
		return dp_data[i][j];
	}
	if (str1[i - 1] == str2[j - 1]) {
		dp_data[i][j] = dp(i - 1, j - 1) + str1[i - 1];
		return dp_data[i][j];
	}
	else {
		auto ans1 = dp(i - 1, j), ans2 = dp(i, j - 1);
		if (ans1.length() > ans2.length()) {
			dp_data[i][j] = ans1;
		}
		else {
			dp_data[i][j] = ans2;
		}
		return dp_data[i][j];
	}
}

void foo::solve() {
	getline(cin, str1);

	str2 = str1;
	int length = str1.length();
	reverse(str2.begin(), str2.end());

	dp_data.resize(length + 1, vector<string>(length + 1, ""));
	auto ans = dp(length, length);
	if (ans.length() % 2) {
		ans.erase(ans.length() / 2, 1);
	}
	cout << ans;
}
