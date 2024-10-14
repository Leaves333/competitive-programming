#include <bits/stdc++.h>
using namespace std;

int colors[100001];
vector<int> adjacencies[100001];
vector<pair<int, int>> edges;
map<pair<int, int>, int> edge_counts;

void dfs(int cur, int start, vector<pair<int, int>> &s, unordered_set<int> &visited) {

	visited.insert(cur);
	if (colors[cur] == colors[start]) {
		for (auto edge : s) {
			edge_counts[edge]++;
		}
	}
	
	for (int dest : adjacencies[cur]) {
		if (visited.count(dest) == 0) {
			s.push_back(make_pair(min(cur, dest), max(cur, dest)));
			dfs(dest, start, s, visited);
			s.pop_back();
		}
	}

}

int main() {

	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> colors[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		adjacencies[a].push_back(b);
		adjacencies[b].push_back(a);

		auto edge = make_pair(min(a, b), max(a, b));
		edges.push_back(edge);
		edge_counts[edge] = 0;
	}

	for (int start = 1; start <= n; start++) {
		vector<pair<int, int>> s;
		unordered_set<int> visited;
		dfs(start, start, s, visited);
	}

	for (auto edge : edges) {
		cout << edge_counts[edge] / 2 << endl;
	}
	
}
