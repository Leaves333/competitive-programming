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

	const int MASK = 0x7ffffffc;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vi arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		
		// find groups of indices that can be swapped
		// sort these groups
		// profit??

		unordered_map<int, priority_queue<int>> groups;
		groups.reserve(1024);
		groups.max_load_factor(0.1);
		for (int i = 0; i < n; i++) {
			groups[arr[i] & MASK].push(-arr[i]);
		}
		for (int i = 0; i < n; i++) {
			int group = arr[i] & MASK;
			cout << -groups[group].top() << " ";
			groups[group].pop();
		}
		cout << endl;

	}
}
