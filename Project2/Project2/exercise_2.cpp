#include "std_lib_facilities.h"
#include "Polynomial.h"
#include <iomanip>
#include <tuple>

void cut_o(string& s) {
	int pos = s.find('.');
	if (pos == s.npos) {
		s += ".0000";
	}
	else {
		while (pos + 4 >= s.length())
			s += '0';
	}
	s = s.substr(0, pos + 5);
}

int main()
{
	//����ļ�Ŀ¼�޸�Polynomial.h��Polynomial.cpp����exercise_2.cpp
	/********** Begin **********/

	bool exercise1 = false;
	if (exercise1) {
		//��һ��ִ�д���
		string str;
		getline(cin, str);
		double val;
		cin >> val;
		try {
			Polynomial expr(str);
			expr.print();
			auto g = expr.grad();
			g.print();
			string out = to_string(expr.calculate(val));
			cut_o(out);
			cout << out;
		}
		catch (...) {
			cout << "error\nerror\nerror";
		}
	}
	else {
		//�ڶ���ִ�д���
		string str1, str2;
		getline(cin, str1);
		getline(cin, str2);

		try {
			Polynomial expr1(str1), expr2(str2), ans, remain;
			tie(ans, remain) = expr1.devide(expr2);
			ans.print();
			cout << endl;
			remain.print();
		}
		catch (...) {
			cout << "error\nerror";
		}
	}
	/********** End **********/
	return 0;
}

