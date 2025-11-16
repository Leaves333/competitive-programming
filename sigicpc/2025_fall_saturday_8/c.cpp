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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int LIMIT = 200010;
    int SQRT_LIMIT = sqrt(LIMIT) + 2;
    vvi dp(LIMIT, vi(SQRT_LIMIT));

    for (int i = 0; i < LIMIT; i++) {
        for (int j = 1; j < SQRT_LIMIT; j++) {
            if (j == 1) {
                dp[i][j] = 1;
                continue;
            }

            if (j - 1 > 0) {
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= MOD;
            }
            if (i - j >= 0) {
                dp[i][j] += dp[i - j][j];
                dp[i][j] %= MOD;
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int square_size = (n % 2) + 2 * (n % 2 == 0);
        ll ans = 0;
        while (square_size * square_size <= n) {
            int remaining = n - (square_size * square_size);
            remaining /= 2;
            ans += dp[remaining][square_size];
            ans %= MOD;
            square_size += 2;
        }
        cout << ans << endl;
    }
}
