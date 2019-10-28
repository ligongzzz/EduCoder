#include "std_lib_facilities.h"
#include "Token_Exercise_1.h"
#include "Code_Exercise_2.h"

int main()
{
	/********** Begin **********/

	bool exercise_1 = false;
	if (exercise_1) {
		//第一关执行代码
			//Please fix Token_Exercise_1.h and Token_Exercise_1.cpp
		string str;
		getline(cin, str);
		Token token;
		token.add(str);
		getline(cin, str);
		token.dest(str);
		token.find();
		token.strcmp_sort();
		token.print();
	}
	else {
		//第二关执行代码
		//Please fix Code_Exercise_2.h and Code_Exercise_2.cpp
		string str;
		Code code;
		while (getline(cin, str)) {
			code.add(str);
		}
		code.parse();
		code.print();
	}
	/********** End **********/
	return 0;
}

