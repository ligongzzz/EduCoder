#include "std_lib_facilities.h"
#include "Question_1.h"
#include <iostream>

void boat::solve() {
	int w, n;
	cin >> w >> n;
	vector<int> vdata(n);
	vector<bool> vistied(n, false);
	for (int i = 0; i < n; ++i) {
		cin >> vdata[i];
		if (vdata[i] <= 0) {
			cout << "error";
			return;
		}
	}
	for (auto p : vdata)
		if (p > w) {
			cout << "out";
			return;
		}

	sort(vdata.begin(), vdata.end());
	int cnt = 0;
	for (int i = 0, j = n - 1; i <= j && i < n; ++cnt, ++i, --j) {
		
		for (; i < j && vdata[i] + vdata[j] > w; --j, ++cnt);
		if (i == j) {
			++cnt;
			break;
		}
	}
	cout << cnt;
}