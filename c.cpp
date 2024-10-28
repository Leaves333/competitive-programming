#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n;
	int m;
	cin >> n >> m;

	const int changes[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
	set<pair<int, int>> seen;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		seen.insert(make_pair(a, b));
		for (auto d : changes) {
			int new_a = a + d[0];
			int new_b = b + d[1];
			if (new_a < 1 || new_b < 1 || new_a > n || new_b > n) {
				continue;
			} else {
				seen.insert(make_pair(new_a, new_b));
			}
		}
	}

	cout << (n * n) - seen.size() << endl;
}
