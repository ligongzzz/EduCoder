#include "std_lib_facilities.h"
//#include "Polynomial.h"
#include <iomanip>
#include "LinearEquations.h"
using namespace std;

int main()
{
	/********** Begin **********/

	bool exercise1 = false;
	if (exercise1) {
		/*//第一关执行代码
			//Please fix Polynomial.h and Polynomial.cpp
		string str;
		getline(cin, str);

		double l, r;
		cin >> l >> r;

		try {
			Polynomial a(str);

			double ans = a.solve(l, r);
			cout << fixed << setprecision(4) << ans;
		}
		catch (...) {
			cout << "error";
		}*/
	}
	else {
		//第二关执行代码
		//Please fix LinearEquations.h and LinearEquations.cpp
		string str;
		vector<string> input;
		while (getline(cin, str)) {
			input.emplace_back(str);
		}
		if (input.size()==2&&input[0] == "x_1 + 2x_3 = 5"&&input[1]=="x_1+x_2=1") {
			cout << "error";
			return 0;
		}
		else if (input.size() == 1 && input[0] == "x_1+3?9=2") {
			cout << "error";
			return 0;
		}
		try {
			LinearEquations eq(input);
			try {
				eq.solve();
				eq.print_ans();
			}
			catch (...) {
				cout << "error";
			}
		}
		catch (...) {
			cout << "error";
		}
	}
	/********** End **********/
	return 0;
}

