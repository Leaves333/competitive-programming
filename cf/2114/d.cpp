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
        vector<pll> monsters(n);
        vll x_coords(n), y_coords(n);

        for (int i = 0; i < n; i++) {
            ll x, y;
            cin >> x_coords[i] >> y_coords[i];
            monsters[i] = {x_coords[i], y_coords[i]};
        }

        if (n <= 2) {
            cout << n << endl;
            continue;
        }

        vector<pll> boundary;
        sort(monsters.begin(), monsters.end(), [](const pll &a, const pll &b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        /*cout << "monsters: " << endl;*/
        /*for (auto m : monsters) {*/
        /*    cout << m.first << " " << m.second << endl;*/
        /*}*/
        /*cout << endl;*/

        for (int i = 0; i < 2; i++) {
            boundary.push_back(monsters[i]);
            boundary.push_back(monsters[n - 1 - i]);
        }

        sort(monsters.begin(), monsters.end(), [](const pll &a, const pll &b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        });

        /*cout << "monsters: " << endl;*/
        /*for (auto m : monsters) {*/
        /*    cout << m.first << " " << m.second << endl;*/
        /*}*/
        /*cout << endl;*/

        for (int i = 0; i < 2; i++) {
            boundary.push_back(monsters[i]);
            boundary.push_back(monsters[n - 1 - i]);
        }

        ll ans = LLONG_MAX;
        for (int i = 0; i < boundary.size(); i++) {
            ll smol_x = INT_MAX;
            ll big_x = INT_MIN;
            ll smol_y = INT_MAX;
            ll big_y = INT_MIN;

            for (pll p : monsters) {
                if (boundary[i] == p)
                    continue;

                smol_x = min(smol_x, p.first);
                big_x = max(big_x, p.first);
                smol_y = min(smol_y, p.second);
                big_y = max(big_y, p.second);
            }

            ll area = (big_x - smol_x + 1) * (big_y - smol_y + 1);
            if (area < n)
                area = n;
            ans = min(ans, area);
        }

        cout << ans << endl;

    }
}
