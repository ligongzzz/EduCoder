#include "std_lib_facilities.h"
#include <vector>
#include <map>
using namespace std;


class LinearEquations {
	vector<vector<double>> A_val;
	vector<double> B_val;
	vector<double> X_val;
	map<int, int> mdata;
	int eq_num = 0, va_num = 0;

	void parse_value(const string& s, int op);
	void parse_string(const string& s, int op);
	void add_to_expr(double, int);
	vector<double> solve(const vector<vector<double>>& A, const vector<double>& B);
public:
	LinearEquations(const vector<string>& s);
	LinearEquations(const LinearEquations&) = default;

	void solve();
	void print_ans();
};