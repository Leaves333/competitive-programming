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
        ll h, n;
        cin >> h >> n;
        vll damage(n), cooldown(n);
        for (int i = 0; i < n; i++) {
            cin >> damage[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> cooldown[i];
        }

        ll l = 0, r = 1e10;
        while (l < r) {
            ll mid = l + (r - l + 1) / 2;

            ll tot = 0;
            for (int i = 0; i < n; i++) {
                tot += (mid / cooldown[i]) * damage[i];
            }

            if (tot >= h) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        cout << l << endl;
    }
}
