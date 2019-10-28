#include "std_lib_facilities.h"
#include <map>
using namespace std;

class Interpolation {
	map<double, double> mdata;
public:
	void insert(double, double);
	double cal(double);
};