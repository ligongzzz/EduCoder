#include "Graph.h"
#include "std_lib_facilities.h"

class hyperelliptic :public Graph_lib::Shape {
	double delta_x = 0.0;
	vector<pair<double, double>> origin_points;
public:
	double a = 0.0, b = 0.0, m = 0.0, n = 0.0;
	int N = 0;
	
	hyperelliptic() = default;
	hyperelliptic(double a, double b, double m, double n, int N,
		double center_x = 300.0, double center_y = 200.0);

	//Strech the shape.
	void fit_window(double x_s = 1.0, double y_s = 1.0, double x_m = 0.0, double y_m = 0.0);
protected:
	virtual void draw_lines() const;
};