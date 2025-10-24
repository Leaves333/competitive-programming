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
        int k, d;
        cin >> k >> d;
        string s;
        cin >> s;

        // sum[i] is a prefix sum of the number of 0s
        vi sum(s.length() + 1);
        for (int i = 0; i < s.length(); i++) {
            sum[i + 1] = sum[i] + (s[i] == '0');
        }

        // dp[i][j] stores maximum considering first i, using at most j
        vvi dp(s.length() + 1, vi(k + 1, 0));
        int ans = 0;
        for (int i = 0; i < s.length() + 1; i++) {
            for (int j = 0; j <= k; j++) {
                if (i < d) {
                    dp[i][j] = 0;
                } else {
                    int target = j - (sum[i] - sum[i - d]);
                    dp[i][j] = dp[i - 1][j];
                    if (target >= 0) {
                        dp[i][j] = max(dp[i][j], dp[i - d][target] + 1);
                    }
                }
                ans = max(ans, dp[i][j]);
            }
        }

        cout << ans << endl;
    }
}
