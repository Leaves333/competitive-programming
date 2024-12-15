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
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;

        ll ans = 0, factor = 1;
        for (int n = 0; n < 70; n++) {
            if (factor > r2) break;
            // find lowest val such that val * factor > l2
            ll low = l1, high = r1 + 1;
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (mid * factor >= l2) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            ll left_bound = low;

            // find highest val such that val * factor > r2
            low = l1, high = r1 + 1;
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (mid * factor > r2) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            ll right_bound = low;
            /*cout << n << " " << factor << " " << left_bound << " " << right_bound << endl;*/
            ans += right_bound - left_bound;
            factor *= k;
        }
        cout << ans << endl;
    }
}
