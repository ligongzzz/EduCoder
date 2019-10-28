#include "righttriangle.h"

void righttriangle::draw_lines() const{
	Point p1(c_x, c_y),
		p2(c_x + len_1 * cos(angle), c_y + len_1 * sin(angle)),
		p3(c_x - len_2 * sin(angle), c_y + len_2 * cos(angle));
	fl_line(p1.x, p1.y, p2.x, p2.y);
	fl_line(p2.x, p2.y, p3.x, p3.y);
	fl_line(p3.x, p3.y, p1.x, p1.y);
}

righttriangle::righttriangle(double len_1, double len_2, double c_x, double c_y,
	double angle) :len_1(len_1), len_2(len_2), c_x(c_x), c_y(c_y), angle(angle) {
	draw();
}