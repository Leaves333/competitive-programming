#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	set<int> edges[n];
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].insert(b);
		edges[b].insert(a);
	}

	set<int> required;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		required.insert(x - 1);
	}
	
	vector<int> degree;
	for (auto v : edges) {
		degree.push_back(v.size());
	}

	vector<int> queue;
	for (int i = 0; i < degree.size(); i++) {
		if (degree[i] == 1) {
			queue.push_back(i);
		}
	}

	int ans = n;
	for (int i = 0; i < queue.size(); i++) {

		int v = queue[i];
		if (required.count(v) > 0) {
			continue;
		}

		int adj = *edges[v].begin();
		edges[adj].erase(v);
		edges[v].clear();

		if (edges[adj].size() == 1) {
			queue.push_back(adj);
			ans--;
		}

	}

	cout << ans << endl;

}
