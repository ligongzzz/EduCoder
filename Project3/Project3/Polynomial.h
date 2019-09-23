#include "std_lib_facilities.h"
#include <map>
#include <tuple>

class Polynomial {
	//The vector data of the expression.
	map<int, double> expr;
	bool status = true;

	//Parse the string.
	void parse_string(const string& s);
	//Parse the value.
	void parse_value(const string& v);
	//Add into the expr.
	void add_to_expr(double a, int b);
	//Simplify the expr.
	void simplify();
public:
	Polynomial() = default;
	Polynomial(const string& s);

	void print();
	double calculate(double val);
	double solve(double l, double r);
	Polynomial grad();
};