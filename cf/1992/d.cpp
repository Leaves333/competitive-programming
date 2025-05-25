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
        int n, m, k;
        cin >> n >> m >> k;
        string river;
        cin >> river;
        river = "L" + river + "L";

        // min num of meters swam to get to pos
        vll dp(n + 2, INT_MAX);
        dp[0] = 0;

        int amount_swam = 0;
        for (int i = 0; i < n + 2; i++) {
            if (river[i] == 'C')
                continue;
            if (river[i] == 'L') {
                for (int j = 1; j <= m; j++) {
                    if (i+j >= n+2)
                        break;
                    dp[i+j] = min(dp[i], dp[i+j]);
                }
            }
            if (i+1 < n+2)
                dp[i+1] = min(dp[i] + 1, dp[i+1]);
        }

        if (dp[n+1] <= k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }
}
