#include "Graph.h"
#include "Binary_tree.h"
#include "std_lib_facilities.h"

class TriangleBinary_tree :public Binary_tree {
public:
	TriangleBinary_tree() = default;
	TriangleBinary_tree(int levels, double sh = 50.0, double sx = 300.0, double sy = 50.0);
	
protected:
	virtual void draw_point() const;
};