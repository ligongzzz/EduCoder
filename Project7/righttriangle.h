#include "Graph.h"
#include "std_lib_facilities.h"

class righttriangle :public Graph_lib::Shape {
public:
	double len_1 = 0.0, len_2 = 0.0;
	double c_x = 0.0, c_y = 0.0;
	double angle = 0.0;
	righttriangle() = default;
	righttriangle(double len_1, double len_2, double c_x, double c_y,
		double angle = 0.0);

protected:
	virtual void draw_lines() const;
};
