#include "std_lib_facilities.h"
#include <map>
#include <queue>

class Huffman {
	class node {
	public:
		char s = 0;
		int val = 1, index = 0,
			lchild = -1, rchild = -1, parent = -1;
		bool code = false;
		node() = default;
		node(const char& s) :s(s) {}

		bool operator<(const node& rhs) const {
			return val > rhs.val;
		}
	};
	priority_queue<node> qdata;
	map<char, node> mdata;
	vector<node> node_list;
	int head_pos;
public:
	Huffman(string s);
	vector<bool> encode(string s);
};