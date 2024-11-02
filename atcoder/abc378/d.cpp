#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dfs(int x, int y, int k, vector<string>& grid, set<pair<int, int>> visited) {

	if (k == 0) {
		return 1;
	}

	int count = 0;
	visited.insert(make_pair(x, y));

	int changes[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	for (int i = 0; i < 4; i++) {

		int new_x = x + changes[i][0];
		int new_y = y + changes[i][1];

		// check oob
		if (new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[0].length()) {
			continue;
		}

		// check valid square
		if (grid[new_x][new_y] == '#' || visited.count(make_pair(new_x, new_y))) {
			continue;
		}

		count += dfs(new_x, new_y, k - 1, grid, visited);

	}
	return count;
}

int main() {
	int h, w, k;
	cin >> h >> w >> k;
	vector<string> grid(h);
	for (int i = 0; i < h; i++) {
		cin >> grid[i];
	}

	ll ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (grid[i][j] == '#') {
				continue;
			}
			ans += dfs(i, j, k, grid, set<pair<int, int>>());
		}
	}
	cout << ans << endl;
}
