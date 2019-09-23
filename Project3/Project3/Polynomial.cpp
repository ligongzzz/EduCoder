#include "std_lib_facilities.h"
#include "Polynomial.h"
#include <iomanip>
#include <tuple>

void Polynomial::parse_string(const string& s) {
	int length = s.length();
	for (int i = 1; i < length; ++i) {
		if (s[i] == '+') {
			parse_value(s.substr(0, i));
			parse_string(s.substr(i + 1));
			return;
		}
		else if (s[i] == '-') {
			parse_value(s.substr(0, i));
			parse_string(s.substr(i));
			return;
		}
	}
	parse_value(s);
}

void Polynomial::add_to_expr(double a, int b) {
	if (expr.find(b) == expr.end())
		expr.insert(make_pair(b, a));
	else
		expr[b] += a;
}

int strtoi(const string& s) {
	for (int i = 1; i < s.length(); ++i) {
		if (s[i]<'0' || s[i]>'9')
			throw "Error expression!";
	}
	return stoi(s);
}

double strtof(const string& s) {
	bool rn = false;
	for (int i = 1; i < s.length(); ++i) {
		if (s[i] == '.') {
			if (!rn)
				rn = true;
			else
				throw "Too many points!";
		}
		else if (s[i]<'0' || s[i]>'9')
			throw "Error expression!";
	}
	return double(stof(s));
}

void Polynomial::parse_value(const string& v) {
	int pos = v.find('x');
	if (pos == string::npos) {
		add_to_expr(strtof(v), 0);
	}
	else {
		if (pos < v.length() - 1) {
			if (v[pos + 1] == '^') {
				if (pos == 0) {
					add_to_expr(1, strtoi(v.substr(pos + 2)));
				}
				else if (pos == 1 && v[0] == '-')
					add_to_expr(-1, strtoi(v.substr(pos + 2)));
				else
					add_to_expr(strtof(v.substr(0, pos)), strtoi(v.substr(pos + 2)));
			}
			else {
				throw "Error expression!";
			}
		}
		else {
			if (pos == 0)
				add_to_expr(1, 1);
			else if (pos == 1 && v[0] == '-')
				add_to_expr(-1, 1);
			else
				add_to_expr(strtof(v.substr(0, pos)), 1);
		}
	}
}

Polynomial::Polynomial(const string& s) {
	parse_string(s);
}

void cut_s(string& s) {
	int pos = s.find('.');
	if (pos == s.npos) {
		s += ".0000";
	}
	else {
		while (pos + 4 >= s.length())
			s += '0';
		s = s.substr(0, pos + 5);
	}
}

void Polynomial::print() {
	if (!status) {
		cout << "error";
		return;
	}
	bool flag = false;
	for (auto p = expr.rbegin(); p != expr.rend(); ++p) {
		if (p->second == 0)
			continue;
		if (flag && p->second > 0) {
			cout << "+";
		}
		auto out = to_string(p->second);
		cut_s(out);
		cout << out;
		if (p->first > 0) {
			cout << "x";
			if (p->first > 1) {
				cout << "^" << p->first;
			}
		}
		flag = true;
	}
	if (!flag)
		cout << "0.0000";
}

Polynomial Polynomial::grad() {
	Polynomial ans;
	for (auto& p : expr) {
		if (p.first == 0)
			ans.add_to_expr(0, 0);
		else
			ans.add_to_expr(p.first * p.second, p.first - 1);
	}
	return ans;
}

double Polynomial::calculate(double val) {
	double ans = 0.0;
	for (auto& p : expr) {
		ans += p.second * pow(val, p.first);
	}
	return ans;
}

void Polynomial::simplify() {
	for (auto p = expr.begin(); p != expr.end();) {
		if (p->second == 0)
			expr.erase(p++);
		else
			++p;
	}
	if (expr.empty())
		add_to_expr(0, 0);
}

double Polynomial::solve(double l, double r) {
	auto diff = grad();
	auto diff_diff = diff.grad();
	double ans = (l + r) / 2;
	double diff_diff_init = diff_diff.calculate(ans);
	double diff_init = diff.calculate(ans);
	if (calculate(l) * calculate(r) >= 0)
		throw "Error when solve the equation!";

	for (double i = l; i < r; i += (r - l) / 1000) {
		double diff_ans = diff.calculate(i);
		if (diff_ans * diff_init <= 0)
			throw "Error";
	}

	while (true) {
		double diff_ans = diff.calculate(ans);
		double diff_diff_ans = diff_diff.calculate(ans);
		if (diff_diff_ans * diff_diff_init < 0)
			throw "Error when solve the equation!";
		if (abs(diff_ans) <= 1e-10)
			throw "Error when solve the equation!";
		double nxt = ans - calculate(ans) / diff.calculate(ans);
		if (nxt<l || nxt>r)
			throw "Error when solve the equation!";
		if (abs(ans - nxt) < 1e-5)
			break;
		ans = nxt;
	}

	return ans;
}