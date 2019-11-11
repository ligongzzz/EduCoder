#include "Huffman_Exercise_2.h"
#include "std_lib_facilities.h"
#include <map>
#include <queue>

Huffman2::Huffman2(string s) {
	//Input
	int length = s.length();
	for (int i = 0, j = 0; j <= length; ++j) {
		if (j == length || !((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z'))) {
			if (i == j) {
				++i;
				continue;
			}
			auto temp = s.substr(i, j - i);
			i = j + 1;
			if (mdata.find(temp) == mdata.end()) {
				mdata.insert(make_pair(temp, node(temp)));
			}
			else {
				++mdata[temp].val;
			}
		}
	}

	//Parse
	for (auto& p : mdata) {
		p.second.index = node_list.size();
		qdata.push(p.second);
		node_list.emplace_back(p.second);
	}
	while (qdata.size() > 1) {
		auto p1 = qdata.top();
		qdata.pop();
		auto p2 = qdata.top();
		qdata.pop();
		node tmp;
		tmp.val = p1.val + p2.val;
		tmp.lchild = p1.index;
		tmp.rchild = p2.index;
		tmp.index = node_list.size();
		node_list[p1.index].parent = node_list[p2.index].parent = tmp.index;
		node_list[p1.index].code = false;
		node_list[p2.index].code = true;
		if (!p1.s.empty())
			mdata[p1.s] = node_list[p1.index];
		if (p2.s.empty())
			mdata[p2.s] = node_list[p2.index];
		node_list.emplace_back(tmp);
		qdata.push(tmp);
	}
	head_pos = qdata.top().index;
}

vector<bool> Huffman2::encode(string s) {
	vector<bool> ans;
	//Input
	int length = s.length();
	for (int i = 0, j = 0; i < length; ++j) {
		if (j == length || !((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z'))) {
			if (i == j) {
				for (int k = 0; k < 8; ++k)
					ans.emplace_back(false);
				++i;
				continue;
			}
			auto tmp = s.substr(i, j - i);
			i = j;
			--j;
			vector<bool> cur_ans;
			for (int p = mdata[tmp].index; p != head_pos; p = node_list[p].parent) {
				cur_ans.emplace_back(node_list[p].code);
			}
			for (int p = cur_ans.size() - 1; p >= 0; --p) {
				ans.emplace_back(cur_ans[p]);
			}
		}
	}

	return ans;
}