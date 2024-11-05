#include <bits/stdc++.h>
using namespace std;

int max_depth(int loc, int depth, vector<int> edges[], vector<bool>& visited, vector<int>& depths, vector<int>& children_depths) {
	visited[loc] = true;
	depths[depth]++;

	int child_max_depth = depth;
	for (int dest : edges[loc]) {
		if (visited[dest]) {
			continue;
		}
		child_max_depth = max(child_max_depth,
						max_depth(dest, depth + 1, edges, visited, depths, children_depths));
	}
	children_depths[child_max_depth]++;
	return child_max_depth;
}

int main() {

	// maintain prefix sum of depths of nodes
	// and max depth of children's nodes

	int t; cin >> t;
	while (t--) {

		int n; cin >> n;
		vector<int> edges[n + 1];
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}

		vector<int> depths(n, 0);
		vector<int> children_depths(n, 0);

		vector<bool> visited = vector<bool>(n + 1, false);
		max_depth(1, 0, edges, visited, depths, children_depths);

		vector<int> psum_depths(n + 1, 0);
		vector<int> psum_children_depths(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			psum_depths[i] = psum_depths[i - 1] + depths[i -1];
			psum_children_depths[i] = psum_children_depths[i - 1] + children_depths[i -1];
		}

		int ans = INT_MAX;
		for (int i = 0; i < n; i++) {
			int operations = psum_children_depths[i] + psum_depths[n] - psum_depths[i + 1];
			ans = min(ans, operations);
		}
		cout << ans << endl;

	}
}
