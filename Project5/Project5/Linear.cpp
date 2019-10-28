#include "SimpleLinearRegression.h"
#include "std_lib_facilities.h"

void Linear::insert(double x, double y) {
	vdata.emplace_back(make_pair(x, y));
}

void Linear::fit() {
	if (vdata.empty())
		throw "Empty data!";
	double xsum = 0.0, ysum = 0.0, xysum = 0.0, x2sum = 0.0, y2sum = 0.0,
		n = vdata.size();
	for (auto p : vdata) {
		xsum += p.first;
		ysum += p.second;
		xysum += p.first * p.second;
		x2sum += p.first * p.first;
		y2sum += p.second * p.second;
	}

	a = (xysum - 1.0 / n * xsum * ysum) / (x2sum - 1.0 / n * xsum * xsum);
	b = ysum / n - a * xsum / n;
	r = (xysum - 1.0 / n * xsum * ysum) / sqrt((x2sum - xsum * xsum / n) * (y2sum - ysum * ysum / n));
}

double Linear::estimate(double x) {
	return a * x + b;
}