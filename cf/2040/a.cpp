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

		int n, k;
		cin >> n >> k;

		vi arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		bool solution_found = false;
		for (int i = 0; i < n; i++) {
			bool good = true;
			for (int j = 0; j < n; j++) {
				if (j == i) continue;
				if (abs(arr[i] - arr[j]) % k == 0) {
					good = false;
					break;
				}
			}
			if (good) {
				cout << "YES" << endl;
				cout << i + 1 << endl;
				solution_found = true;
				break;
			}
		}

		if (!solution_found) {
			cout << "NO" << endl;
		}

	}
}
