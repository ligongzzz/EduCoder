#include "std_lib_facilities.h"

class Linear {
	vector<pair<double, double>> vdata;
public:
	double a = 0.0, b = 0.0, r = 0.0;

	Linear() = default;
	void insert(double x, double y);
	void fit();
	double estimate(double x);
};