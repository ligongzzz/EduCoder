#include "Graph.h"
#include "AnalogClock.h"
#include "std_lib_facilities.h"
#include <ctime>
#include <iostream>

#define CLOCK_RELEASE

void AnalogClock::draw_clock() const {
	using namespace Graph_lib;

	auto t = time(NULL);
	auto local = localtime(&t);

#ifdef CLOCK_DEBUG
	cerr << local->tm_hour << ":" << local->tm_min << ":" << local->tm_sec << endl;
#endif // CLOCK_DEBUG

	const double PI = 3.1415926535;
	// Calculate the angel.
	double hour_a = (local->tm_hour % 12) / 12.0 * 2 * PI,
		min_a = (local->tm_min) / 60.0 * 2 * PI,
		sec_a = (local->tm_sec) / 60.0 * 2 * PI;
	min_a += sec_a / 60;
	hour_a += min_a / 12;
	string hour_str = to_string(local->tm_hour),
		min_str = to_string(local->tm_min),
		sec_str = to_string(local->tm_sec);
	auto expand_str = [](string& a) {if (a.length() < 2) a = '0' + a; };
	expand_str(hour_str), expand_str(min_str), expand_str(sec_str);
	string date_str = to_string(local->tm_year + 1900) + "." +
		to_string(local->tm_mon + 1) + "." + to_string(local->tm_mday),
		time_str = hour_str + ":" + min_str + ":" + sec_str;

	//Paint the background.
	Graph_lib::Rectangle rect_back(Point(0, 0), Point(600, 600));
	rect_back.set_fill_color(Color::white);
	rect_back.draw();

	//Paint the clock.
	Circle clock_circle(Point(300, 300), clock_r),
		center_circle(Point(300, 300), center_r);
	clock_circle.set_fill_color(Color::white);
	clock_circle.set_color(Color::black);
	clock_circle.set_style(Line_style::solid);
	center_circle.set_fill_color(Color::black);
	center_circle.set_color(Color::black);
	center_circle.set_style(Line_style::solid);
	clock_circle.draw();
	center_circle.draw();

	// Paint the labels.
	for (int i = 0; i < 60; ++i) {
		double angle = i / 60.0 * 2.0 * PI;
		if (i % 5) {
			Line l(Point(300 + label_r1 * sin(angle), 300 - label_r1 * cos(angle)),
				Point(300 + label_r2 * sin(angle), 300 - label_r2 * cos(angle)));
			l.set_color(Color::black);
			l.set_style(Line_style(Line_style::solid,2));
			l.draw();
		}
		else {
			Line l(Point(300 + label_r3 * sin(angle), 300 - label_r3 * cos(angle)),
				Point(300 + label_r2 * sin(angle), 300 - label_r2 * cos(angle)));
			l.set_color(Color::black);
			l.set_style(Line_style(Line_style::solid, 3));
			l.draw();
			Text t(Point(300 + (label_r3 - 20) * sin(angle) - 7 * to_string(i == 0 ? 12 : i / 5).length(),
				300 - (label_r3 - 20) * cos(angle) + 10),
				to_string(i == 0 ? 12 : i / 5));
			t.set_color(Color::black);
			t.set_font_size(30);
			t.draw();
		}
	}

	// Print the strings.
	Text text_date(Point(270, 375), date_str), text_time(Point(273, 400), time_str);
	text_date.set_color(Color::black);
	text_time.set_color(Color::black);
	text_date.set_font_size(15);
	text_time.set_font_size(15);
	text_date.draw();
	text_time.draw();

	// Draw the pointer.
	Line line_hour(Point(300, 300), Point(300 + hour_l * sin(hour_a), 300 - hour_l * cos(hour_a))),
		line_min(Point(300, 300), Point(300 + min_l * sin(min_a), 300 - min_l * cos(min_a))),
		line_sec(Point(300, 300), Point(300 + sec_l * sin(sec_a), 300 - sec_l * cos(sec_a)));

	line_hour.set_color(Color::red);
	line_min.set_color(Color::blue);
	line_sec.set_color(Color::black);

	line_hour.set_style(Line_style(Line_style::solid, hour_w));
	line_min.set_style(Line_style(Line_style::solid, min_w));
	line_sec.set_style(Line_style(Line_style::solid, sec_w));

	line_hour.draw();
	line_min.draw();
	line_sec.draw();
}

void AnalogClock::draw_lines() const{
	while (true) {
		draw_clock();
		Sleep(1000);
	}
}