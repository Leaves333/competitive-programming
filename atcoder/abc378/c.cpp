#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	unordered_map<int, int> last_seen;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (last_seen.count(x) == 0) {
			cout << -1 << " ";
		} else {
			cout << last_seen[x] << " ";
		}
		last_seen[x] = i + 1;
	}
	cout << endl;
}
