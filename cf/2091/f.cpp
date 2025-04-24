#include <algorithm>
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

const int MOD = 998244353;
bool in_dist(int x1, int y1, int x2, int y2, int d) {
    ll xdiff = x1 - x2;
    ll ydiff = y1 - y2;
    ll dist = (xdiff * xdiff) + (ydiff * ydiff);
    return dist <= (d * d);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {

        int n, m, d;
        cin >> n >> m >> d;
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        // bottom row is at grid[0]
        reverse(grid.begin(), grid.end());

        vvll dp_first(n, vll(m, 0));
        vvll dp_second(n, vll(m, 0));
        
        // dp_first of everything on the first level is 1
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 'X')
                dp_first[0][i] = 1;
        }

        // calculate dp_second
        for (int i = 0; i < m; i++) {
            if (grid[0][i] != 'X')
                continue;
            for (int j = 0; j < m; j++) {
                if (!in_dist(0, i, 0, j, d))
                    continue;
                if (i == j)
                    continue;
                dp_second[0][i] += dp_first[0][j];
            }
            dp_second[0][i] %= MOD;
        }

        for (int i = 1; i < n; i++) {

            // calculate dp_first
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 'X')
                    continue;
                for (int k = 0; k < m; k++) {
                    if (!in_dist(i, j, i - 1, k, d))
                        continue;
                    dp_first[i][j] += dp_first[i - 1][k];
                    dp_first[i][j] += dp_second[i - 1][k];
                }
                dp_first[i][j] %= MOD;
            }

            // calculate dp_second
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 'X')
                    continue;
                for (int k = 0; k < m; k++) {
                    if (!in_dist(i, j, i, k, d))
                        continue;
                    if (j == k)
                        continue;
                    dp_second[i][j] += dp_first[i][k];
                }
                dp_second[i][j] %= MOD;
            }

        }

        ll ans = 0;
        for (int i = 0; i < m; i++) {
            ans += dp_first[n - 1][i];
            ans += dp_second[n - 1][i];
            ans %= MOD;
        }
        cout << ans << endl;
        
    }
}
