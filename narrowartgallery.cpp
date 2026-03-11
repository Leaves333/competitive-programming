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

const int LEFT = 0;
const int RIGHT = 1;
const int NEITHER = 2;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    while (true) {
        int n, k;
        cin >> n >> k;
        if (n == 0 && k == 0)
            break;

        ll sum = 0;
        vll left(n), right(n);
        for (int i = 0; i < n; i++) {
            cin >> left[i] >> right[i];
            sum += left[i] + right[i];
        }

        // dp[i][j][k] stores the min considering the first i, having taken j
        vector<vvll> dp(n, vvll(k + 1, vll(3, INT_MAX)));
        dp[0][0][NEITHER] = 0;
        if (k > 0) {
            dp[0][1][LEFT] = left[0];
            dp[0][1][RIGHT] = right[0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k + 1; j++) {
                dp[i][j][NEITHER] =
                    min(dp[i - 1][j][NEITHER],
                        min(dp[i - 1][j][LEFT], dp[i - 1][j][RIGHT]));
                if (j > 0) {
                    dp[i][j][LEFT] =
                        min(dp[i - 1][j - 1][LEFT], dp[i - 1][j - 1][NEITHER]) +
                        left[i];
                    dp[i][j][RIGHT] = min(dp[i - 1][j - 1][RIGHT],
                                          dp[i - 1][j - 1][NEITHER]) +
                                      right[i];
                }
            }
        }

        ll min_cost = min(dp[n - 1][k][NEITHER],
                          min(dp[n - 1][k][LEFT], dp[n - 1][k][RIGHT]));
        ll ans = sum - min_cost;
        cout << ans << endl;
    }
}
