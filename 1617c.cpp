#pragma optimize("O3")

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

		vector<bool> seen(n + 1, false);
		sort(arr.begin(), arr.end());
		int left = 1, ans = 0;
		for (int i = 0; i < n; i++) {

		}
	}
}
