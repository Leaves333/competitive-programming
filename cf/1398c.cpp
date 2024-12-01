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
		string str; cin >> str;
		vll psum(n + 1);
		for (int i = 0; i < n; i++) {
			psum[i + 1] = psum[i] + (str[i] - '0' - 1);
		}
		
		ll ans = 0;
		map<ll, int> previously_seen;
		previously_seen[0]++;

		for (int i = 1; i <= n; i++) {
			ans += previously_seen[psum[i]];
			previously_seen[psum[i]]++;
		}

		cout << ans << endl;
	}
}
