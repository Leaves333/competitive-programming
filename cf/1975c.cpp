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
		vi nums(n);
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}
		if (n == 2) {
			cout << min(nums[0], nums[1]) << endl;
			continue;
		}
		int ans = 0;
		for (int i = 0; i < n - 2; i++) {
			priority_queue<int> pq;
			pq.push(nums[i]);
			pq.push(nums[i + 1]);
			pq.push(nums[i + 2]);
			pq.pop();
			ans = max(ans, pq.top());
		}
		cout << ans << endl;
	}
}
