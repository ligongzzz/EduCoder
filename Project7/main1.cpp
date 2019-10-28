
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities
#include "hyperelliptic.h"
#include <iostream>

//------------------------------------------------------------------------------

int main()
{
	using namespace Graph_lib;   // our graphics facilities are in Graph_lib

	Point tl(100, 100);           // to become top left  corner of window
	double a, b, m, n;
	int N;
	cin >> a >> b >> m >> n >> N;
	Simple_window win(tl, 600, 400, "hyperelliptic");    // make a simple window

	
	hyperelliptic shape(a, b, m, n, N);
	shape.set_color(1);
	shape.set_style(Line_style::solid);
	

	win.attach(shape);           // connect poly to the window

	win.wait_for_button();       // give control to the display engine
}

//------------------------------------------------------------------------------
