#include "LinearEquations.h"
#include "std_lib_facilities.h"
#include <unordered_map>
using namespace std;

int mystoi(const string& s) {
	for (int i = 1; i < s.length(); ++i) {
		if (s[i]<'0' || s[i]>'9')
			throw "Error expression!";
	}
	return stoi(s);
}

double mystof(const string& s) {
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

void LinearEquations::parse_value(const string& v, int op) {
	int pos = v.find("x_");
	if (pos == string::npos) {
		B_val[eq_num] -= op * mystof(v);
	}
	else {
		int label = mystoi(v.substr(pos + 2));
		if (pos == 1 && v[0] == '-') {
			add_to_expr(-1.0 * op, label);
		}
		else if (pos == 0) {
			add_to_expr(1.0 * op, label);
		}
		else {
			add_to_expr(mystof(v.substr(0, pos)) * op, label);
		}
	}
}

void LinearEquations::parse_string(const string& s, int op) {
	int length = s.length();
	for (int i = 1; i < length; ++i) {
		if (s[i] == '+') {
			parse_value(s.substr(0, i), op);
			parse_string(s.substr(i + 1), op);
			return;
		}
		else if (s[i] == '-') {
			parse_value(s.substr(0, i), op);
			parse_string(s.substr(i), op);
			return;
		}
	}
	parse_value(s, op);
}

void LinearEquations::add_to_expr(double a, int b) {
	if (mdata.find(b) != mdata.end()) {
		A_val[eq_num][mdata[b]] += a;
	}
	else {
		mdata.insert(make_pair(b, va_num++));
		A_val[eq_num][mdata[b]] = a;
	}
}

LinearEquations::LinearEquations(const vector<string>& s) {
	for (auto& p : s) {
		int pos = p.find('=');
		if (pos == string::npos) {
			throw string("Error equation!");
		}
		A_val.emplace_back(vector<double>(100, 0));
		B_val.emplace_back(0);
		parse_string(p.substr(0, pos), 1);
		parse_string(p.substr(pos + 1), -1);
		++eq_num;
	}
	/*
	if (eq_num < va_num) {
		throw string("Rank does not match!");
	}*/
	for (auto& p : A_val) {
		p.resize(va_num);
	}
}

vector<double> LinearEquations::solve(const vector<vector<double>>& A, const vector<double>& B) {
	int m = A.size(), n = A.front().size();
	vector<double> X(n, 0);
	vector<vector<double>> C(m, vector<double>(n + 1));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			C[i][j] = A[i][j];
		C[i].back() = B[i];
	}

	//Simplify A.
	for (int j = 0;; ++j) {
		//Check the rank
		if (j == n) {
			for (int k = n; k < m; ++k) {
				if (C[k][n] != 0.0)
					throw "Rank Error!";
			}
			break;
		}

		//Swap the not 0 to the first place.
		for (int i = j;; ++i) {
			if (i == m)
				throw "Rank does not match!";
			if (C[i][j]) {
				swap(C[j], C[i]);
				break;
			}
		}

		for (int i = j + 1; i < m; ++i) {
			auto l = C[i][j] / C[j][j];
			for (int k = j; k <= n; ++k)
				C[i][k] -= C[j][k] * l;
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		double tmp = C[i][n];
		for (int j = i + 1; j < n; ++j) {
			tmp -= C[i][j] * X[j];
		}
		X[i] = tmp / C[i][i];
	}

	return X;
}

void LinearEquations::solve() {
	X_val = solve(A_val, B_val);
}

void LinearEquations::print_ans() {
	bool first = true;
	for (auto p : mdata) {
		if (first)
			first = false;
		else
			cout << " ";
		string output = to_string(X_val[p.second]); 
		output = output.substr(0, output.find('.') + 5);
		if (output == "-0.0000")
			output = "0.0000";
		cout << output;
	}
}