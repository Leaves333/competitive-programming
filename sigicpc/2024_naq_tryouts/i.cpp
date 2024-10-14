#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;
	string grid[n];

	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}

	vector<pair<int, int>> lights;
	set<pair<int, int>> open_cells;
	map<pair<int, int>, char> blocks;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == '?') {
				lights.push_back(make_pair(i, j));
			} else if (grid[i][j] != '.') {
				blocks[make_pair(i, j)] = grid[i][j];
			} else {
				open_cells.insert(make_pair(i, j));
			}
		}
	}

	set<pair<int, int>> scanned_cells;
	for (auto light : lights) {

		for (int i = light.first + 1; i < n; i++) {
			if (grid[i][light.second] == '?') {
				cout << 0 << endl;
				return 0;
			} else if (grid[i][light.second] != '.') {
				break;
			} else {
				scanned_cells.insert(make_pair(i, light.second));
			}
		}

		for (int i = light.first - 1; i >= 0; i--) {
			if (grid[i][light.second] == '?') {
				cout << 0 << endl;
				return 0;
			} else if (grid[i][light.second] != '.') {
				break;
			} else {
				scanned_cells.insert(make_pair(i, light.second));
			}
		}

		for (int i = light.second + 1; i < n; i++) {
			if (grid[light.first][i] == '?') {
				cout << 0 << endl;
				return 0;
			} else if (grid[light.first][i] != '.') {
				break;
			} else {
				scanned_cells.insert(make_pair(light.first, i));
			}
		}

		for (int i = light.second - 1; i >= 0; i--) {
			if (grid[light.first][i] == '?') {
				cout << 0 << endl;
				return 0;
			} else if (grid[light.first][i] != '.') {
				break;
			} else {
				scanned_cells.insert(make_pair(light.first, i));
			}
		}
	}

	if (scanned_cells.size() != open_cells.size()) {
		cout << 0 << endl;
		return 0;
	}

	for (auto block : blocks) {
		pair<int, int> coords = block.first;
		char value = block.second;

		if (value == 'X') {
			continue;
		}

		int target = value - '0';
		int adjacent_lights = 0;
		if (coords.first + 1 < n && grid[coords.first + 1][coords.second] == '?') {
			adjacent_lights++;
		}
		if (coords.first - 1 >= 0 && grid[coords.first - 1][coords.second] == '?') {
			adjacent_lights++;
		}
		if (coords.second + 1 < n && grid[coords.first][coords.second + 1] == '?') {
			adjacent_lights++;
		}
		if (coords.second - 1 >= 0 && grid[coords.first][coords.second - 1] == '?') {
			adjacent_lights++;
		}

		if (adjacent_lights != target) {
			cout << 0 << endl;
			return 0;
		}
	}
	
	cout << 1 << endl;
}
