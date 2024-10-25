#include <bits/stdc++.h>
using namespace std;

bool dfs(const pair<int, int> cur, const pair<int, int> last, const vector<string>& grid, vector<vector<bool>>& visited) {

	if (visited[cur.first][cur.second]) {
		return true;
	}
	visited[cur.first][cur.second] = true;

	bool found_loop = false;

	int changes[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	for (auto d : changes) {

		pair<int, int> next = make_pair(cur.first + d[0], cur.second + d[1]);

		// check in bounds
		if (next.first < 0 || next.first >= grid.size() || next.second < 0 || next.second >= grid[0].size()) {
			continue;
		}

		// check not last
		if (next.first == last.first && next.second == last.second) {
			continue;
		}

		// check same letter
		if (grid[cur.first][cur.second] != grid[next.first][next.second]) {
			continue;
		}

		found_loop |= dfs(next, cur, grid, visited);
	}

	return found_loop;
}

int main() {

	int n, m;
	cin >> n >> m;

	vector<string> grid(n);
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}

	vector<vector<bool>> visited(n, vector<bool>(m, false));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				if (dfs(make_pair(i, j), make_pair(-1, -1), grid, visited)) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}

	cout << "No" << endl;

}
