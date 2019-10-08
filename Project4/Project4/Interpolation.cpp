#include "std_lib_facilities.h"
#include "Interpolation.h"
#include <map>
using namespace std;

void Interpolation::insert(double x, double y) {
	mdata.insert(make_pair(x, y));
}

double Interpolation::cal(double x) {
	double ans = 0.0;
	vector<double> diff(mdata.size(), 0.0);

	// Check.
	int cnt = 0;
	double last_x = 0.0, gap = 0.0;
	for (auto p : mdata) {
		if (cnt >= 2) {
			if (abs(gap - (p.first - last_x)) > 1e-7)
				throw "ERROR!";
		}
		if (cnt >= 1) {
			gap = p.first - last_x;
		}
		last_x = p.first;
		diff[cnt] = p.second;
		++cnt;
	}
	double x0 = mdata.begin()->first;

	// Calculate.
	double tmp = 1.0;
	for (int i = 0; i < cnt; ++i) {
		ans += diff[0] * tmp;
		for (int j = 0; j + i + 1 < cnt; ++j) {
			diff[j] = (diff[j + 1] - diff[j]) / (gap * (i + 1.0));
		}
		tmp *= x - x0 - i * gap;
	}
	return ans;
}