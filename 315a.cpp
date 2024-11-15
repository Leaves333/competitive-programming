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

	int n; cin >> n;
	map<int, int> bottles;
	map<int, int> openable;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		if (a != b) {
			openable[b] = 1000;
		} else {
			if (openable.count(b) == 0) {
				openable[b] = 1;
			} else {
				openable[b] = 1000;
			}
		}

		bottles[a]++;
	}

	int ans = n;
	for (const auto &[type, ct] : bottles) {
		if (openable[type] == 1) {
			ans -= ct - 1;
		} else {
			ans -= min(ct, openable[type]);
		}
	}
	cout << ans << endl;
	
}
