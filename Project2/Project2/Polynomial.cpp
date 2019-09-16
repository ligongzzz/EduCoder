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
			if(pos==0)
				add_to_expr(1, 1);
			else if(pos==1&&v[0]=='-')
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

tuple<Polynomial, Polynomial> Polynomial::devide(const Polynomial& rhs) {
	simplify();
	auto other = rhs;
	other.simplify();
	Polynomial ans_o, remain_o;
	int h1 = expr.rbegin()->first, h2 = other.expr.rbegin()->first;
	if (h2 == 0 && other.expr.at(0) == 0) {
		throw "Devide by zero!";
	}
	else if (h1 < h2) {
		return tie(ans_o, *this);
	}
	vector<double> ans(h1 + 1, 0), remain(h1 + 1, 0), d2(h2 + 1, 0);
	for (auto p : expr)
		remain[p.first] = p.second;
	for (auto p : other.expr)
		d2[p.first] = p.second;

	//Begin
	for (int pos = 0; pos + h2 <= h1; ++pos) {
		double tmp = remain[h1 - pos] / d2.back();
		ans[h1 - h2 - pos] = tmp;
		for (int i = 0; i <= h2; ++i) {
			remain[h1 - h2 - pos + i] -= tmp * d2[i];
		}
	}

	for (int i = 0; i <= h1; ++i) {
		if (ans[i] != 0)
			ans_o.add_to_expr(ans[i], i);
		if (remain[i] != 0)
			remain_o.add_to_expr(remain[i], i);
	}

	return tie(ans_o, remain_o);
}