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
		int ans = 0;
		map<int, int> seen;
		while (n--) {
			int x; cin >> x;
			int y = x ^ INT_MAX;
			if (seen.count(y) && seen[y] > 0) {
				seen[y]--;
			} else {
				seen[x]++;
				ans++;
			}
		}
		cout << ans << endl;
	}
}