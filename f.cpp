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

    ll n, m, q;
    cin >> n >> m >> q;

    ll row_sum = 0, col_sum = 0;
    vi a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        row_sum += a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        col_sum += b[i];
    }

    ll total_sum = row_sum * col_sum;
    cout << "total: " << total_sum << endl;
    set<int> possible;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            ll val = (-1 * (b[c] * row_sum + a[r] * col_sum)) + (a[r] * b[r]);
            possible.insert(val);
            cout << r << " " << c << " " << val << endl;
        }
    }

    while (q--) {
        ll x; cin >> x;
        if (possible.count(x - total_sum)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        // pick r, c such that - (b[col] * row_sum) - (a[row] * col_sum) + (a[row] * b[col]) = x - total
    }
}
