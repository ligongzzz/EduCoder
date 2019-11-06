#include "Graph.h"
#include "std_lib_facilities.h"
#include <ctime>

class AnalogClock :public Graph_lib::Shape {
public:
	//Parameters
	int clock_r = 250, hour_l = 150, min_l = 200, sec_l = 220,
		hour_w = 10, min_w = 8, sec_w = 3, center_r = 20,
		label_r1 = 232, label_r2 = 245, label_r3 = 230;

	AnalogClock() = default;
	void sub_thread() const;
protected:
	virtual void draw_lines() const;
	void draw_clock() const;
};
