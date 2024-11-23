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
		vi arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int m; cin >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			a--; b--;

			int closest;
			if (a == 0 || arr[a + 1] - arr[a] < arr[a] - arr[a - 1]) { closest = arr[a + 1]; }
			else if (a == n - 1 || arr[a] - arr[a - 1] < arr[a + 1] - arr[a]) { closest = arr[a - 1]; }
			int ans = min(abs(arr[a] - arr[b]), 1 + abs(closest - arr[b]));
			cout << ans << endl;
		}
	}
}
