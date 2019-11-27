#include "std_lib_facilities.h"
#include <iostream>
#include "Question_2.h"

void subsequence::solve() {
	int n;
	cin >> n;
	if (n > 10000 || n <= 0) {
		cout << "error";
		return;
	}
	vector<int> vdata(n);
	for (int i = 0; i < n; ++i) {
		cin >> vdata[i];
		if (vdata[i] > 1000 || vdata[i] < -1000) {
			cout << "error";
			return;
		}
	}
	int smin = 0, imin = -1;
	int ans = vdata[0], ansl = -1, ansr = 0;

	for (int i = 0, s = 0; i < n; ++i) {
		s += vdata[i];
		if (s - smin > ans) {
			ans = s - smin;
			ansl = imin;
			ansr = i;
		}
		if (s < smin) {
			smin = s;
			imin = i;
		}
	}
	cout << ans << " " << ansl + 2 << " " << ansr + 1;
}