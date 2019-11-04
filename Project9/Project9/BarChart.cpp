#include "BarChart.h"
#include "Graph.h"
#include "std_lib_facilities.h"
#include <iostream>

void BarChart::load_data() {
	auto f = fopen("./Austin.csv", "rt");
	char tmp[100];
	fscanf(f, "%s", tmp);
	int year, month, day, cur_month = 1, cur_mon_cnt = 0;
	double t, cur_mon_sum = 0.0;
	while (~fscanf(f, "%d/%d/%d,%lf ,", &year, &month, &day, &t)) {
		if (month != cur_month) {
			val1.emplace_back(cur_mon_sum / (double)cur_mon_cnt);
			cur_month += 1, cur_mon_cnt = 0, cur_mon_sum = 0;
		}
		cur_mon_sum += t, ++cur_mon_cnt;
	}
	val1.emplace_back(cur_mon_sum / (double)cur_mon_cnt);
	cur_month = 1, cur_mon_cnt = 0, cur_mon_sum = 0;
	fclose(f);
	
	f = fopen("./NewYork.csv", "rt");
	fscanf(f, "%s", tmp);
	while (~fscanf(f, "%d/%d/%d,%lf ,", &year, &month, &day, &t)) {
		if (month != cur_month) {
			val2.emplace_back(cur_mon_sum / (double)cur_mon_cnt);
			cur_month += 1, cur_mon_cnt = 0, cur_mon_sum = 0;
		}
		cur_mon_sum += t, ++cur_mon_cnt;
	}
	val2.emplace_back(cur_mon_sum / (double)cur_mon_cnt);
	fclose(f);
}

void BarChart::draw_lines() const {
	Graph_lib::Rectangle rect_back(Point(0, 0), Point(1050, 450));
	rect_back.set_fill_color(Graph_lib::Color::white);
	rect_back.set_color(Graph_lib::Color::white);
	rect_back.set_style(Graph_lib::Line_style::solid);
	rect_back.draw();

	Graph_lib::Axis x(Graph_lib::Axis::x, Point(50, 410), 960);
	x.set_color(Graph_lib::Color::black);
	x.set_style(Graph_lib::Line_style::solid);
	x.draw();

	Graph_lib::Axis y(Graph_lib::Axis::y, Point(50, 410), 350, 7, "temperature(C)");
	y.set_color(Graph_lib::Color::black);
	y.set_style(Graph_lib::Line_style::solid);
	y.draw();

	// Y Text
	for (int i = 0; i <= 7; ++i) {
		Graph_lib::Text text(Point(20, 410 + 5 - 50 * i), to_string(5 * i));
		text.set_color(Graph_lib::Color::black);
		text.draw();
	}

	// X Text
	for (int i = 1; i <= 12; ++i) {
		Graph_lib::Text text(Point(50 + 75 * i - 3, 410 + 20), to_string(i));
		text.set_color(Graph_lib::Color::black);
		text.draw();
	}

	// Graph Data
	for (int i = 1; i <= 12; ++i) {
		int cur_x = 50 + 75 * i;
		int h1 = int(10 * val1[i - 1]), h2 = int(10 * val2[i - 1]);
		Graph_lib::Rectangle rect1(Point(cur_x - 23, 410 - h1), Point(cur_x - 3, 410));
		rect1.set_fill_color(Graph_lib::Color::red);
		rect1.draw();
		Graph_lib::Rectangle rect2(Point(cur_x + 3, 410 - h2), Point(cur_x + 23, 410));
		rect2.set_fill_color(Graph_lib::Color::blue);
		rect2.draw();

		// Draw Val Text
		Graph_lib::Text text1(Point(cur_x - 22, 410 - h1 - 3), to_string(int(val1[i - 1])));
		text1.set_color(Graph_lib::Color::red);
		text1.draw();

		Graph_lib::Text text2(Point(cur_x + 5, 410 - h2 - 3), to_string(int(val2[i - 1])));
		text2.set_color(Graph_lib::Color::blue);
		text2.draw();
	}

	// Tag
	Graph_lib::Rectangle tag_rect(Point(860,50), Point(1010,110));
	tag_rect.set_color(Graph_lib::Color::black);
	tag_rect.set_style(Graph_lib::Line_style::solid);
	tag_rect.draw();
	Graph_lib::Rectangle rect1(Point(870, 60), Point(910, 70));
	rect1.set_fill_color(Graph_lib::Color::red);
	rect1.draw();
	Graph_lib::Rectangle rect2(Point(870, 90), Point(910, 100));
	rect2.set_fill_color(Graph_lib::Color::blue);
	rect2.draw();
	Graph_lib::Text text1(Point(930, 70), "Austin");
	text1.set_color(Graph_lib::Color::black);
	text1.draw();
	Graph_lib::Text text2(Point(930, 100), "New York");
	text2.set_color(Graph_lib::Color::black);
	text2.draw();
}
