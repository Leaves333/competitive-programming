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

    int t;
    cin >> t;
    while (t--) {
        set<ll> vals;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            vals.insert(x);
        }

        // task is for each x, find the smallest int relatively coprime
        // only need to check up to ~80, as product of all primes up to 53 >
        // 10^18
        ll limit = 81;
        ll ans = LLONG_MAX;
        for (ll x : vals) {
            for (ll i = 2; i < limit; i++) {
                if (gcd(x, i) == 1) {
                    ans = min(ans, i);
                    break;
                }
            }
        }

        cout << ans << endl;
    }
}
