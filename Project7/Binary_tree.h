#pragma once

#include "Graph.h"
#include "std_lib_facilities.h"

class Binary_tree :public Graph_lib::Shape {
public:
	double sh;
	int levels = 0;
	double sx, sy;
	double gap_h = 10.0;

	Binary_tree() = default;
	Binary_tree(int levels, double sh = 50.0, double sx = 300.0, double sy = 50.0);

	void set_gap_h(double h);

protected:
	virtual int draw_single_line(int pos, int levels) const;
	virtual void draw_lines() const;
	virtual void draw_point() const;
	void add_point(double l, double r, double x, double y, int levels);
};