#include "std_lib_facilities.h"
#include <map>
#include <unordered_set>
#include <algorithm>

class NodeRecognition {
	class node {
	public:
		node() = default;
		node(int x) :weight(x) {}
		int weight = 0;
		vector<int> child_list, parent_list;
	};
	class graph_type {
	public:
		graph_type(int type, int weight, int size, string type_str) :type(type), weight(weight), size(size), type_str(type_str) {}
		//node, bin tree, tree, graph.
		string type_str;
		int type = 0;
		int weight = 0, size = 0;
	};
	map<int, node> sdata;
	vector<graph_type> ans_data;

	pair<int, int> dfs(int pos, unordered_set<int>& visited, int& max_in, int& max_out, int& min_in) {
		max_in = max(max_in, int(sdata[pos].parent_list.size()));
		max_out = max(max_out, int(sdata[pos].child_list.size()));
		min_in = min(min_in, int(sdata[pos].parent_list.size()));
		pair<int, int> ans(pos, 1);
		visited.insert(pos);
		for (auto p : sdata[pos].parent_list) {
			if (visited.find(p) == visited.end()) {
				auto r = dfs(p, visited, max_in, max_out, min_in);
				ans.first += r.first;
				ans.second += r.second;
			}
		}
		for (auto p : sdata[pos].child_list) {
			if (visited.find(p) == visited.end()) {
				auto r = dfs(p, visited, max_in, max_out, min_in);
				ans.first += r.first;
				ans.second += r.second;
			}
		}
		return ans;
	}
public:
	void insert(string str) {
		str = str.substr(1, str.length() - 2);
		if (str.length() == 0) {
			return;
		}
		int pos = str.find(' ');
		if (pos == string::npos) {
			int weight = stoi(str);
			if (sdata.find(weight) == sdata.end()) {
				sdata.insert(make_pair(weight, node(weight)));
			}
		}
		else {
			int w1 = stoi(str.substr(0, pos)), w2 = stoi(str.substr(pos + 1));
			if (sdata.find(w1) == sdata.end())
				sdata.insert(make_pair(w1, node(w1)));
			if (sdata.find(w2) == sdata.end())
				sdata.insert(make_pair(w2, node(w2)));
			sdata[w1].parent_list.emplace_back(w2);
			sdata[w2].child_list.emplace_back(w1);
		}
	}

	void parse() {
		unordered_set<int> visited;
		for (auto p : sdata) {
			if (visited.find(p.first) != visited.end())
				continue;
			int max_in = 0, max_out = 0, min_in = 100;
			auto cur_ans = dfs(p.first, visited, max_in, max_out, min_in);
			if (max_in == 0 && max_out == 0)
				ans_data.emplace_back(graph_type(0, cur_ans.first, cur_ans.second, "Node"));
			else if (max_in == 1 && max_out <= 2 && min_in == 0)
				ans_data.emplace_back(graph_type(1, cur_ans.first, cur_ans.second, "Binary tree"));
			else if (max_in == 1 && min_in == 0) 
				ans_data.emplace_back(graph_type(2, cur_ans.first, cur_ans.second, "Tree"));
			else ans_data.emplace_back(graph_type(3, cur_ans.first, cur_ans.second, "Graph"));
		}
		sort(ans_data.begin(), ans_data.end(), [](graph_type& a, graph_type& b) {
			return a.type < b.type || (a.type == b.type && a.weight < b.weight) ||
				(a.type == b.type && a.weight == b.weight && a.size < b.size);
			});
	}
	void print() {
		cout << "We have recognized " << ans_data.size() << " graph";
		if (ans_data.size() > 1)
			cout << 's';
		cout << '.';
		for (auto& p : ans_data) 
			cout << endl << "--" << p.type_str << ". Weight: " << p.weight << ". Size: " << p.size << ".";
	}
};