#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

// returns count, sum
pll solve(ll l, ll r, ll k) {

    pll ret = make_pair(0, 0);
    if (r - l < k - 1) {
        return ret;
    }

    ll m = (l + r) / 2;
    pll first_half;
    if ((r - l + 1) % 2 == 0) {
        first_half = solve(l, m, k);
    } else {
        first_half = solve(l, m - 1, k);
        ret.first++;
        ret.second += m;
    }
    ret.second += first_half.first * m;
    ret.first += first_half.first * 2;
    ret.second += first_half.second * 2;

    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        cout << solve(1, n, k).second << endl;
    }
}
