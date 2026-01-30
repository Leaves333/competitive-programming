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

ll solve_query_one(ll x, ll t) {

    // first it falls vertically for some time, then we can loop
    // x will be in position x from time=x to time=x + falling_time
    ll cur = x; // current time
    ll falling_time = max(0ll, x - 1);
    cur += falling_time;

    if (cur >= t) {
        return x;
    }

    // simulate while we aren't far enough
    ll pos = x;
    while (cur < t) {
        cur += pos + 1; // it goes all the way to the front
        pos = cur / 2;  // and then moves to t/2
    }

    ll diff = cur - t;
    if (diff == 0) {
        return pos;
    } else {
        return diff - 1;
    }
}

ll solve_query_two(ll x, ll t) {

    // if > t/2, then output x
    // otherwise, find the diagonal stripe its on,
    // and follow it back to the beginning

    if (x > t/2) {
        return x;
    }

    if (x + t < 2) {
        return 0;
    }

    if ((x + t) % 3 == 2) {
        return ((x + t) / 3ll) + 1ll;
    }

    ll limit = (x + t + 1) / 3;
    ll diff = limit - x;
    ll new_t = t - diff - 1;
    return solve_query_two(0, new_t);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int q;
    cin >> q;
    while (q--) {
        ll op, x, t;
        cin >> op >> x >> t;

        if (op == 1) {
            cout << solve_query_one(x, t) << endl;
        } else {
            cout << solve_query_two(x, t) << endl;
        }
    }
}
