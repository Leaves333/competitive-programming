#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	int energy_cost[n + 1];
	vector<pair<int, int>> index_and_cost(n + 1, make_pair(0, 0));
	for (int i = 0; i < n; i++) {
		cin >> energy_cost[i + 1];
		index_and_cost[i + 1] = make_pair(energy_cost[i + 1], i + 1);
	}
	sort(index_and_cost.begin(), index_and_cost.end());
	reverse(index_and_cost.begin(), index_and_cost.end());
	
	vector<int> edges[n + 1];
	int connections[n + 1];
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		edges[a].push_back(b);
		edges[b].push_back(a);
		connections[a]++;
		connections[b]++;
	}

	bool removed[n + 1];
	memset(removed, false, sizeof(removed));
	int ans = 0;

	for (auto p : index_and_cost) {
		removed[p.second] = true;
		for (int dest : edges[p.second]) {
			if (!removed[dest]) {
				ans += energy_cost[dest];
			}
		}
	}
	
	cout << ans << endl;

}
