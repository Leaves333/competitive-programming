#include <bits/stdc++.h>
using namespace std;

void dfs(int cur, vector<int> edges[], vector<int>& group, unordered_set<int>& visited) {
	group.push_back(cur);
	visited.insert(cur);

	for (int dest : edges[cur]) {
		if (visited.count(dest) == 0) {
			dfs(dest, edges, group, visited);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> edges[n + 1];
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	unordered_set<int> visited;
	vector<vector<int>> groups;
	vector<vector<int>> groups_of_two;
	vector<vector<int>> groups_of_one;

	for (int i = 1; i <= n; i++) {
		if (visited.count(i) > 0) {
			continue;
		}

		vector<int> group;
		dfs(i, edges, group, visited);

		if (group.size() > 3) {
			cout << -1 << endl;
			return 0;
		} else if (group.size() == 3) {
			groups.push_back(group);
		} else if (group.size() == 2) {
			groups_of_two.push_back(group);
		} else if (group.size() == 1) {
			groups_of_one.push_back(group);
		}
	}

	if ((groups_of_one.size() - groups_of_two.size()) % 3 != 0 || groups_of_two.size() > groups_of_one.size()) {
		cout << -1 << endl;
		return 0;
	}

	for (auto group : groups) {
		cout << group[0] << " " << group[1] << " " << group[2] << endl;
	}

	for (int i = 0; i < groups_of_two.size(); i++) {
		cout << groups_of_one[i][0] << " " << groups_of_two[i][0] << " " << groups_of_two[i][1] << endl;
	}

	for (int i = groups_of_two.size(); i < groups_of_one.size(); i += 3) {
		cout << groups_of_one[i][0] << " " << groups_of_one[i + 1][0] << " " << groups_of_one[i + 2][0] << endl;
	}

}
