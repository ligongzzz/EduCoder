#pragma once

#include "Graph.h"
#include "std_lib_facilities.h"

class BarChart :public Graph_lib::Shape {
	vector<double> val1, val2;
public:
	BarChart() = default;
	void load_data();
	virtual void draw_lines() const;
};
