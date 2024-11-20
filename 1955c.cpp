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
		ll n, k;
		cin >> n >> k;
		vll arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int left = 0, right = n - 1;
		while (k > 0 && left < right) {
			ll smol = min(arr[left], arr[right]);
			if (k >= 2 * smol) {
				k -= 2 * smol;
				arr[left] -= smol;
				arr[right] -= smol;
			} else {
				arr[right] -= k / 2;
				arr[left] -= (k + 1) / 2;
				k = 0;
			}

			if (arr[left] == 0) {
				left++;
			}
			if (arr[right] == 0) {
				right--;
			}
		}

		cout << (left + n - right - 1) + (left == right && arr[left] <= k) << endl;
	}
}
