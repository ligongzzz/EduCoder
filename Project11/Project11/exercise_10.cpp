#include <iostream>
#include "std_lib_facilities.h"
#include "Question_1.h"
#include "Question_2.h"
#include "Question_3.h"
using namespace std;

int main()
{
	/********** Begin **********/
	//int exercise = 1;
	//int exercise = 2;
	int exercise = 3;

	if (exercise == 1) {
		//第一关执行代码
		//Please fix Question_1.h and Question_1.cpp
		boat b;
		b.solve();
	}
	else if (exercise == 2) {
		//Please fix Question_2.h and Question_2.cpp  
		subsequence s;
		s.solve();
	}
	else if (exercise == 3) {
		//Please fix Question_3.h and Question_3.cpp
		foo f;
		f.solve();
	}
	else
		cout << "error";

	/********** End **********/
	return 0;
}

