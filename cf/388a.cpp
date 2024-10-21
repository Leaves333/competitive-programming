#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;
	int boxes[n];

	for (int i = 0; i < n; i++) {
		cin >> boxes[i];
	}

	sort(boxes, boxes + n);

	int ans = 0;
	bool used[n];
	for (int i = 0; i < n; i++) {
		used[i] = false;
	}

	for (int i = 0; i < n; i++) {
		int boxes_stacked = 0;
		for (int j = 0; j < n; j++) {
			if (boxes_stacked <= boxes[j] && !used[j]) {
				used[j] = true;
				boxes_stacked++;
			}
		}
		if (boxes_stacked > 0) {
			ans++;
		}
	}
	
	cout << ans << endl;
	
}
