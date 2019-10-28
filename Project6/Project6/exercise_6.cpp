#include "std_lib_facilities.h"
#include "NodeRecognition.h"

int main()
{
	/********** Begin **********/
	string str;
	getline(cin, str);
	
	try {
		NodeRecognition nodeRecognition;
		for (int i = 0, j = 0; j < str.length(); ++j) {
			if (str[j] == '<')
				i = j;
			if (str[j] == '>') {
				nodeRecognition.insert(str.substr(i, j - i + 1));
			}
		}
		nodeRecognition.parse();
		nodeRecognition.print();
	}
	catch (...) {

	}

	/********** End **********/
	return 0;
}

