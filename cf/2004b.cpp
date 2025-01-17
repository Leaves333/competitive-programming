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
        int a, b, x, y;
        cin >> a >> b >> x >> y;

        int l, r, L, R;
        if (a < x) {
            l = a;
            r = b;
            L = x;
            R = y;
        } else {
            L = a;
            R = b;
            l = x;
            r = y;
        }

        if (r < L) {
            cout << 1 << endl;
        } else if (l == L && r == R) {
            cout << r - l << endl;
        } else if (l == L || r == R) {
            cout << min(r - l, R - L) + 1 << endl;
        } else if (r < R) {
            cout << r - L + 2 << endl;
        } else {
            // r >= R
            cout << R - L + 2 << endl;
        }

    }
}
