#include "hyperelliptic.h"
#include "Graph.h"
#include "std_lib_facilities.h"

void hyperelliptic::draw_lines() const {
	int num = number_of_points();
	for (int i = 0; i < num; ++i) {
		auto p = point(i);
		for (int j = 0; j < num; ++j) {
			if (i == j)
				continue;
			fl_line(p.x, p.y, point(j).x, point(j).y);
		}
	}
}

void hyperelliptic::fit_window(double x_s, double y_s, double x_m, double y_m) {
	for (auto p : origin_points) {
		add(Point(int(p.first * x_s + x_m), int(p.second * y_s + y_m)));
	}
	draw();
}

hyperelliptic::hyperelliptic(double a, double b, double m, double n, int N,
	double center_x, double center_y) :
	a(a), b(b), m(m), n(n), N((N + 2) / 2) {
	N = (N + 2) / 2;
	delta_x = 2.0 * a / (N - 1.0);
	
	for (int i = 0; i < N; ++i) {
		double cur_x = -a + i * delta_x;
		double cur_y = b * pow(1 - pow(abs(cur_x / a), m), 1.0 / n);
		origin_points.emplace_back(make_pair(cur_x, cur_y));
	}

	for (int i = 0; i < N; ++i) {
		origin_points.emplace_back(make_pair(origin_points[N - i - 1].first, 
			-origin_points[N - i - 1].second));
	}

	fit_window(1, 1, center_x, center_y);
}