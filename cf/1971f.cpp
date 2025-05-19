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

    int t; cin >> t;
    while (t--) {
        ll r; cin >> r;
        ll ans = 0;
        for (ll i = 1; i <= r; i++) {

            // greatest value st d^2 < r^2
            ll low = 0, high = r+1;
            while (low < high) {
                ll mid = low + (high - low + 1) / 2;
                ll cur_dist = i*i + mid*mid;
                if (cur_dist < r*r) {
                    low = mid;
                } else {
                    high = mid - 1;
                }
            }
            ll low_bound = low;

            // greatest value st d^2 < (r+1)^2
            low = 0, high = r+1;
            while (low < high) {
                ll mid = low + (high - low + 1) / 2;
                ll cur_dist = i*i + mid*mid;
                if (cur_dist < (r+1)*(r+1)) {
                    low = mid;
                } else {
                    high = mid - 1;
                }
            }
            ll high_bound = low;
            ans += high_bound - low_bound;

        }

        ans *= 4; // 4 quadrants
        ans += 4; // account for four cardinal directions
        cout << ans << endl;

    }
}
