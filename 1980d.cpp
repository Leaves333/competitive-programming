#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

bool good_vector(vi& arr) {
	int last_gcd = gcd(arr[0], arr[1]);
	for (int i = 2; i < arr.size(); i++) {
		int next = gcd(arr[i], arr[i - 1]);
		if (next < last_gcd) { return false; }
		last_gcd = next;
	}
	return true;
}

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

		int last_gcd = gcd(arr[0], arr[1]);
		int bad_idx = -1;
		for (int i = 2; i < n; i++) {
			int next = gcd(arr[i], arr[i - 1]);
			if (next < last_gcd) {
				bad_idx = i - 1;
			}
			last_gcd = next;
		}

		// no bad index
		if (bad_idx == -1) {
			cout << "YES" << endl;
			continue;
		}

		vi remove_prev = arr;
		vi remove_cur = arr;
		vi remove_next = arr;
		remove_prev.erase(remove_prev.begin() + bad_idx - 1);
		remove_cur.erase(remove_cur.begin() + bad_idx);
		remove_next.erase(remove_next.begin() + bad_idx + 1);

		if (good_vector(remove_prev) || good_vector(remove_cur) || good_vector(remove_next)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

	}
}
