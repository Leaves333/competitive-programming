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

		vi cost_going_right(n);
		cost_going_right[0] = 0;
		cost_going_right[1] = 1;
		for (int i = 2; i < n; i++) {
			if (arr[i] - arr[i - 1] < arr[i - 1] - arr[i - 2]) {
				cost_going_right[i] = cost_going_right[i - 1] + 1;
			} else {
				cost_going_right[i] = cost_going_right[i - 1] + arr[i] - arr[i - 1];
			}
		}

		vi cost_going_left(n);
		cost_going_left[n - 1] = 0;
		cost_going_left[n - 2] = 1;
		for (int i = n - 3; i >= 0; i--) {
			if (arr[i + 2] - arr[i + 1] > arr[i + 1] - arr[i]) {
				cost_going_left[i] = cost_going_left[i + 1] + 1;
			} else {
				cost_going_left[i] = cost_going_left[i + 1] + arr[i + 1] - arr[i];
			}
		}

		int m; cin >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			a--; b--;

			if (a < b) {
				cout << cost_going_right[b] - cost_going_right[a] << endl;
			} else {
				cout << cost_going_left[b] - cost_going_left[a] << endl;
			}
		}
	}
}
