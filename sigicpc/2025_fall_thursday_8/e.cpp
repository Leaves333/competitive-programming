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
        int n, m, k, d;
        cin >> n >> m >> k >> d;

        vvll depths(n, vll(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> depths[i][j];
            }
        }

        // min cost to have a support built
        vvll dp(n, vll(m));
        for (int i = 0; i < n; i++) {
            multiset<ll> costs;
            costs.insert(1);
            dp[i][0] = 1;

            for (int j = 1; j < m; j++) {
                dp[i][j] = *costs.begin() + depths[i][j] + 1;
                if (j - d - 1 >= 0)
                    costs.erase(costs.find(dp[i][j - d - 1]));
                costs.insert(dp[i][j]);
            }
        }

        vll psum(n + 1);
        for (int i = 0; i < n; i++) {
            psum[i + 1] = psum[i] + dp[i].back();
        }
        
        ll ans = LLONG_MAX;
        for (int i = 0; i + k <= n; i++) {
            ans = min(ans, psum[i + k] - psum[i]);
        }
        cout << ans << endl;
    }
}
