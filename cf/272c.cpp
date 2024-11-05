#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> heights(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> heights[i];
	}

	int m; cin >> m;
	long long height = 0;
	while (m--) {
		int w, h;
		cin >> w >> h;
		
		height = max(height, (long long) heights[w]);
		cout << height << endl;
		height += h;
	}
}
