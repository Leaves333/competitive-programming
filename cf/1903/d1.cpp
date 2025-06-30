#include <climits>
#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, q;
    cin >> n >> q;
    vll vals(n);
    for (int i = 0; i < n; i++) {
        cin >> vals[i];
    }

    while (q--) {
        ll k; cin >> k;

        ll low = 0, high = (1ll << 61);
        while (low < high) {
            ll mid = low + (high - low + 1) / 2;
            // cout << "mid = " << mid << endl;
            
            // cout << "calculating ops needed:" << endl;
            ll ops_needed = 0;
            for (int x : vals) {
                ll ops = 0;
                if (mid >= x) {
                    ops = mid - x;
                } else {
                    ll top = x | mid;
                    // cout << "tip=" << bitset<64>(top) << endl;
                    bool found_one = false;
                    for (int k = 61; k >= 0; k--) {
                        if (found_one && !(mid & (1ll << k))) {
                            top &= LLONG_MAX ^ (1ll << k);
                        }
                        if (top & (1ll << k) && !(x & (1ll << k))) {
                            found_one = true;
                        }
                    }

                    // cout << "mid=" << bitset<64>(mid) << endl;
                    // cout << "top=" << bitset<64>(top) << endl;
                    // cout << "x  =" << bitset<64>(x) << endl;
                    ops = max(0ll, top - x);
                }

                ops_needed += ops;
                if (ops_needed > k) {
                    break;
                }
                // cout << x << " : " << ops << endl;
            }
            // cout << "total ops needed: " << ops_needed << endl;
            // cout << endl;

            if (ops_needed > k) {
                high = mid - 1;
            } else {
                low = mid;
            }
        }

        cout << low << endl;
    }

}
