#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool dfs(int loc, ll target, vector<vector<int>>& edges, vector<int>& values) {

	if (edges[loc].size() <= 0 && target > values[loc]) {
		return false;
	}
	if (target > INT_MAX) {
		return false;
	}

	if (loc == 1) {
		target = max(0ll, target - values[loc]);
	} else if (target > values[loc]) {
		target += target - values[loc];
	}

	bool status = true;
	for (int dest : edges[loc]) {
		if (!status) { break; }
		status &= dfs(dest, target, edges, values);
	}

	return status;
}

int main() {
	int t; cin >> t;
	while (t--) {

		int n; cin >> n;
		vector<int> values(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> values[i];
		}

		vector<vector<int>> edges(n + 1);
		for (int i = 2; i <= n; i++) {
			int parent; cin >> parent;
			edges[parent].push_back(i);
		}

		ll low = 0, high = INT_MAX;
		while (low < high) {
			int mid = low + (high - low + 1) / 2;
			if (dfs(1, mid, edges, values)) {
				low = mid;
			} else {
				high = mid - 1;
			}
		}

		cout << low << endl;

	}
}
