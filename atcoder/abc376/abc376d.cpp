#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	unordered_map<int, vector<int>> edges;
	for (int i = 1; i <= n; i++) {
		edges[i] = vector<int>();
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
	}

	int ans = INT_MAX;
	vector<int> dist(n + 1, INT_MAX);
	bool first_visit = true;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(0, 1));

	while (q.size() > 0) {

		int depth = q.top().first;
		int location = q.top().second;
		q.pop();

		// did we loop back to 1
		if (location == 1 && !first_visit) {
			ans = min(ans, depth);
		}
		first_visit = false;

		if (dist[location] <= depth) {
			continue;
		}
		dist[location] = depth;

		for (int dest : edges[location]) {
			q.push(make_pair(depth + 1, dest));
		}

	}

	cout << (ans == INT_MAX ? -1 : ans) << endl;

}
