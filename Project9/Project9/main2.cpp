
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities
#include "AnalogClock.h"
#include <ctime>
#include <iostream>
#include <thread>

// Change the define to CLOCK_THREAD to create a new thread,
// which will allow you dragging the window.
// But you need to add the parameter "-pthread" when compiling with G++.
#define CLOCK_NO_THREAD

//------------------------------------------------------------------------------

int main()
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Point tl(100,100);// to become top left  corner of window

    Simple_window win(tl,600,600,"Canvas");    // make a simple window
	AnalogClock analogClock;

	win.attach(analogClock);
	// Change the define to CLOCK_THREAD to create a new thread,
	// which will allow you dragging the window.
	// You need to add "-pthread" when compiling with G++.
#ifdef CLOCK_THREAD
	thread th(&AnalogClock::sub_thread, &analogClock);
#endif // CLOCK_THREAD
#ifdef CLOCK_NO_THREAD
	analogClock.sub_thread();
#endif // CLOCK_NO_THREAD


	win.wait_for_button();       // give control to the display engine
}

//------------------------------------------------------------------------------
