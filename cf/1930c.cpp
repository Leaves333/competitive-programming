#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		map<int, int> m;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			m[x + i + 1]++;
		}

		vi ans;
		while (!m.empty()) {
			auto largest = *(m.rbegin());
			ans.push_back(largest.first);
			if (largest.second != 1) {
				m[largest.first - 1] += largest.second - 1;
			}
			m.erase(largest.first);
		}
		for (auto x : ans) {
			cout << x << " ";
		}
		cout << endl;
	}
}
