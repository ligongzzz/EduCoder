#include "std_lib_facilities.h"
#include "Interpolation.h"

void check(string str) {
	int cnt = 0;
	int length = str.length();
	if (str.empty())
		throw "Error!";
	for (int i = 0; i < length; ++i) {
		if (str[i] == '-') {
			if (i != 0)
				throw "Error!";
		}
		else if (str[i] == '.') {
			if (cnt || i == 0 || str[i - 1] == '-')
				throw "Error!";
			++cnt;
		}
		else if (str[i]<'0' || str[i]>'9') {
			throw "Error!";
		}
	}
}

//¶¨Òåmainº¯Êý
int main()
{
	/********** Begin **********/

	try {
		string str;
		getline(cin, str);
		check(str);
		double x = stod(str);

		Interpolation interpolation;
		while (getline(cin, str)) {
			int pos = str.find(' ');
			if (pos == string::npos) {
				cout << "error";
				return 0;
			}
			string str1 = str.substr(0, pos), str2 = str.substr(pos + 1);
			check(str1);
			check(str2);
			interpolation.insert(stod(str1), stod(str2));
		}
		double ans = interpolation.cal(x);
		string ans_str = to_string(ans);
		ans_str = ans_str.substr(0, ans_str.length() - 2);
		if (ans_str == "-0.0000")
			ans_str = "0.0000";
		cout << ans_str;
	}
	catch (...) {
		cout << "error";
	}

	/********** End **********/
	return 0;
}

