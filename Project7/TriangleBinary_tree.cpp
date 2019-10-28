#include "Graph.h"
#include "TriangleBinary_tree.h"
#include "std_lib_facilities.h"
#include "righttriangle.h"
#include "Binary_tree.h"

void TriangleBinary_tree::draw_point() const {
	int num = number_of_points();
	for (int i = 0; i < num; ++i) {
		auto p = point(i);
		righttriangle tri(14.14214, 14.14214, p.x, p.y, 3.1415926 / 4);
	}
}

TriangleBinary_tree::TriangleBinary_tree(int levels, double sh, double sx, double sy) :
	Binary_tree(levels, sh, sx, sy) {
	add_point(0, 2 * sx, sx, sy, levels);
	draw();
}