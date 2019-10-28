
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities
#include "Binary_tree.h"
#include "TriangleBinary_tree.h"
#include "Binary_tree.h"
#include <iostream>
//------------------------------------------------------------------------------

int main()
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Point tl(100,100);           // to become top left  corner of window
	int h;
	std::cin >> h;
    Simple_window win(tl,600,400,"Canvas");    // make a simple window

	
	TriangleBinary_tree binary_tree(h);
	binary_tree.set_color(1);
	binary_tree.set_style(Line_style::solid);
	win.attach(binary_tree);

    win.wait_for_button();       // give control to the display engine
}

//------------------------------------------------------------------------------
