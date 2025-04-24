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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int q; cin >> q;
        while (q--) {
            string op; cin >> op;
            if (op == "->") {
                ll x, y;
                cin >> x >> y;
                x--; y--;

                ll ans = 0;
                for (int i = 0; i < n; i++) {
                    bool xbit = x & (1 << i);
                    bool ybit = y & (1 << i);
                    if (!xbit && !ybit) {
                        ans |= (0ll << (2 * i));
                    } else if (xbit && ybit) {
                        ans |= (1ll << (2 * i));
                    } else if (xbit && !ybit) {
                        ans |= (2ll << (2 * i));
                    } else {
                        ans |= (3ll << (2 * i));
                    }
                }
                cout << ans + 1 << endl;

            } else {
                ll d; cin >> d;
                d--;

                ll x = 0, y = 0;
                for (int i = 0; i < n; i++) {
                    int val = d % 4;
                    d /= 4;
                    if (val == 1) {
                        x |= (1 << i);
                        y |= (1 << i);
                    } else if (val == 2) {
                        x |= (1 << i);
                    } else if (val == 3) {
                        y |= (1 << i);
                    }
                }
                cout << x + 1 << " " << y + 1 << endl;
            }
        }
    }
}
