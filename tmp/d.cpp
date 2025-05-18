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

        int n, k; cin >> n >> k;
        vi nums(n); // 1 if <= k, 0 otherwise
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            nums[i] = ( nums[i] <= k ) ? -1 : 1;
        }

        vi psum(n + 1);
        for (int i = 0; i < n; i++) {
            psum[i + 1] = psum[i] + nums[i];
        }
        
        vi max_dp(n), min_dp(n);
        max_dp[n-1] = nums[n];
        min_dp[n-1] = nums[n];
        for (int i = n-1; i > 0; i--) {
            max_dp[i-1] = max(max_dp[i], nums[i-1]);;
            min_dp[i-1] = min(min_dp[i], nums[i-1]);;
        }

        for (int i = 1; i < n + 1; i++) {
        
        }

    }
}
