#include "std_lib_facilities.h"
#include "SimpleLinearRegression.h"

double mystod(string str) {
	int cnt = 0, length = str.length();
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
		else if (str[i]<'0' || str[i]>'9')
			throw "Error!";
	}
	return stod(str);
}

string mydtos(double val) {
	string str = to_string(val);
	str = str.substr(0, str.length() - 2);
	if (str == "-0.0000")
		str = "0.0000";
	return str;
}

int main() {
	try {
		string xch;
		getline(cin, xch);
		double x = mystod(xch);
		Linear linear;
		string str;
		while (getline(cin, str)) {
			string a, b;
			int pos = str.find(' ');
			if (pos == string::npos) {
				cout << "error\nerror\nerror";
				return 0;
			}
			else {
				a = str.substr(0, pos);
				b = str.substr(pos + 1);
			}
			linear.insert(mystod(a), mystod(b));
		}
		linear.fit();
		cout << mydtos(linear.r) << endl;
		if (abs(linear.r) < 0.75) {
			cout << "error\nerror";
		}
		else {
			cout << "y=" << mydtos(linear.a) << "*x";
			if (linear.b > 0)
				cout << "+";
			cout << mydtos(linear.b) << endl;
			cout << mydtos(linear.estimate(x));
		}
	}
	catch (...) {
		cout << "error\nerror\nerror";
	}

	return 0;
}