#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	unordered_set<int> edges[n];
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		edges[a - 1].insert(b - 1);
		edges[b - 1].insert(a - 1);
	}

	set<int> required;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		required.insert(x - 1);
	}
	
	vector<int> queue;
	for (int i = 0; i < n; i++) {
		if (edges[i].size() == 1) {
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
		ans--;

		if (edges[adj].size() == 1) {
			queue.push_back(adj);
		}

	}

	cout << ans << endl;

}
