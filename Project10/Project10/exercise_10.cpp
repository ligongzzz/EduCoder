#include "std_lib_facilities.h"
#include "Huffman_Exercise_1.h"
#include "Huffman_Exercise_2.h"
int main()
{
	/********** Begin **********/
	bool exercise_1 = false;
	if (exercise_1) {
		//第一关执行代码
		//Please fix Huffman_Exercise_1.h and Huffman_Exercise_1.cpp
		string str;
		string input;
		bool fi = true;
		while (getline(cin, str)) {
			input += str;
			if (fi)
				fi = false;
			else
				input += '\n';
		}
		Huffman huffman(input);
		auto ans = huffman.encode(input);
		cout << ans.size();
	}
	else {
		//Please fix Huffman_Exercise_2.h and Huffman_Exercise_2.cpp  
		string str;
		string input;
		bool fi = true;
		while (getline(cin, str)) {
			input += str;
			if (fi)
				fi = false;
			else
				input += '\n';
		}
		Huffman2 huffman(input);
		auto ans = huffman.encode(input);
		cout << ans.size();
	}
	/********** End **********/
	return 0;
}

