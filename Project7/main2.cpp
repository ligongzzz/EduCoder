
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities
#include "righttriangle.h"

//------------------------------------------------------------------------------

int main()
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Point tl(100,100);           // to become top left  corner of window

    Simple_window win(tl,600,400,"Canvas");    // make a simple window

	const double PI = 3.1415926535897932;
	righttriangle tri[8];
	for (int i = 0; i < 8; ++i) {
		tri[i].len_1 = 100;
		tri[i].len_2 = 100;
		tri[i].c_x = 300.0 + 100 * cos(PI / 4 * i);
		tri[i].c_y = 200.0 + 100 * sin(PI / 4 * i);
		tri[i].angle = PI / 4 * (i - 1);
		tri[i].set_color(i);
		tri[i].set_style(Line_style::solid);
		win.attach(tri[i]);
	}

    win.wait_for_button();       // give control to the display engine
}

//------------------------------------------------------------------------------
