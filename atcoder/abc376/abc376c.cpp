#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> toys(n);
	vector<int> boxes(n - 1);

	for (int i = 0; i < n; i++) {
		cin >> toys[i];
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> boxes[i];
	}

	sort(toys.begin(), toys.end());
	sort(boxes.begin(), boxes.end());

	// greedy: put the largest toy possible in each box
	
	int toys_idx = n - 1;
	int boxes_idx = n - 2;
	int ans = -1;

	while (toys_idx >= 0) {
		if (toys[toys_idx] > boxes[boxes_idx]) {
			if (ans == -1) {
				ans = toys[toys_idx];
				toys_idx--;
				continue;
			} else {
				cout << -1 << endl;
				return 0;
			}
		}
		toys_idx--;
		boxes_idx--;
	}

	cout << ans << endl;

}
