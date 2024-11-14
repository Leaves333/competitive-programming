#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool contains_char(string str, char c) {
	return str[0] == c || str[1] == c;
}

int main() {
	int t; cin >> t;
	while (t--) {

		int n, q;
		cin >> n >> q;
		vector<string> colors(n);
		map<string, vector<int>> portals;
		for (int i = 0; i < n; i++) {
			cin >> colors[i];
			portals[colors[i]].push_back(i);
		}

		while (q--) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			int x = min(a, b);
			int y = max(a, b);

			// they share a portal
			bool found = false;
			for (char color : colors[x]) {
				if (contains_char(colors[y], color)) {
					found = true;
					cout << y - x << endl;
					break;
				}
			}
			if (found) {
				continue;
			}

			// don't share a portal
			int ans = INT_MAX;
			for (const auto &p : portals) {

				// no path
				if (p.first == colors[x] || p.first == colors[y]) {
					continue;
				}
				if (p.second.size() == 0) {
					continue;
				}

				// if there is a value between x and y: (x - y)
				// first value larger than y: (x - y) + (z - y)
				// first value smaller than x: (x - y) + (x - z)
				
				// binary search for locations of x and y
				// maximum index such that arr[i] < x...
				// if x=y, no value
				const vector<int> &arr = p.second;
				int low = -1, high = arr.size() - 1;
				while (low < high) {
					int mid = low + (high - low + 1) / 2;
					if (arr[mid] < x) {
						low = mid;
					} else {
						high = mid - 1;
					}
				}
				int x_pos = low;

				low = -1, high = arr.size() - 1;
				while (low < high) {
					int mid = low + (high - low + 1) / 2;
					if (arr[mid] < y) {
						low = mid;
					} else {
						high = mid - 1;
					}
				}
				int y_pos = low;

				if (x_pos == y_pos) {
					if (x_pos != -1) {
						ans = min(ans, (y - arr[x_pos]) + (x - arr[x_pos]));
					}
					if (y_pos < (int)(arr.size() - 1)) {
						ans = min(ans, (arr[y_pos + 1] - y) + (arr[y_pos + 1] - x));
					}
				} else {
					ans = min(ans, y - x);
				}

			}
			cout << ((ans == INT_MAX) ? -1 : ans) << endl;
		}

	}
}
