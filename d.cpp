#include <cstdint>
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
        int n, x;
        cin >> n >> x;
        vll nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        vll psum(n + 1);
        for (int i = 0; i < n; i++) {
            psum[i + 1] = psum[i] ^ nums[i];
        }
        
        // when is there no solution? when 
        int first_mask = x;

        int second_mask = 0;
        for (int i = 30; i >= 0; i--) {
            if ((1ll << i) & x) {
                second_mask = 1ll << i;
                break;
            }
        }
        second_mask -= 1;

        vll dp(n + 1, INT_MIN);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = psum[i] ^ psum[j];
                if ((diff | first_mask) == first_mask) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        // don't check second mask
        if ((x & (x + 1)) == 0) {
            cout << ((dp[n] == INT_MIN) ? -1 : dp[n]) << endl;
            continue;
        }

        vll second_dp(n + 1, INT_MIN);
        second_dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = psum[i] ^ psum[j];
                if ((diff | second_mask) == second_mask) {
                    second_dp[i] = max(second_dp[i], second_dp[j] + 1);
                }
            }
        }

        if (dp[n] == INT_MIN && second_dp[n] == INT_MIN) {
            cout << -1 << endl;
        } else if (dp[n] == INT_MIN){
            cout << second_dp[n] << endl;
        } else if (second_dp[n] == INT_MIN){
            cout << dp[n] << endl;
        } else {
            cout << max(dp[n], second_dp[n]) << endl;
        }

    }
}
