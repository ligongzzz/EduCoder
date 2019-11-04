
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities
#include "AnalogClock.h"
#include <ctime>
#include <iostream>

//------------------------------------------------------------------------------

int main()
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Point tl(100,100);// to become top left  corner of window

    Simple_window win(tl,600,600,"Canvas");    // make a simple window
	AnalogClock analogClock;

	win.attach(analogClock);

    win.wait_for_button();       // give control to the display engine
}

//------------------------------------------------------------------------------
