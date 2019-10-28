#include "Binary_tree.h"
#include "Graph.h"
#include "std_lib_facilities.h"
#include <iostream>

void Binary_tree::add_point(double l, double r, double x, double y, int levels) {
	add(Point(x, y));
	if (levels > 1) {
		add_point(l, x, (l + x) / 2, y + sh, levels - 1);
		add_point(x, r, (x + r) / 2, y + sh, levels - 1);
	}
}

void Binary_tree::draw_point() const {
	int num = number_of_points();
	for (int i = 0; i < num; ++i) {
		auto p = point(i);
		p.y += 5;
		Graph_lib::Circle circle(p, 5);
		circle.draw_lines();
	}
}

int Binary_tree::draw_single_line(int pos, int level) const {
	if (level <= 1)
		return pos + 1;
	fl_line(point(pos).x, point(pos).y + gap_h, point(pos + 1).x, point(pos + 1).y);
	int nxt = draw_single_line(pos + 1, level - 1);
	fl_line(point(pos).x, point(pos).y + gap_h, point(nxt).x, point(nxt).y);
	pos = draw_single_line(nxt, level - 1);
	return pos;
}

void Binary_tree::draw_lines() const {
	draw_single_line(0, levels);
	draw_point();
}

Binary_tree::Binary_tree(int levels, double sh, double sx, double sy) :
	levels(levels), sh(sh), sx(sx), sy(sy) {
	add_point(0, 2 * sx, sx, sy, levels);
}

void Binary_tree::set_gap_h(double h) {
	gap_h = h;
}