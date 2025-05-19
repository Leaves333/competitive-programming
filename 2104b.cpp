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
        vll nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        vll min_dp(n);
        min_dp[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            min_dp[i] = min(min_dp[i+1], nums[i]);
        }

        vll max_dp(n);
        max_dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            max_dp[i] = max(max_dp[i-1], nums[i]);
        }

        vll psum(n+1);
        for (int i = 0; i < n; i++) {
            psum[i+1] = psum[i] + nums[i];
        }

        for (int i = 1; i < n; i++) {
            ll first = psum[n] - psum[n - i];
            ll second = psum[n] - psum[n - i + 1] + max_dp[n - i];
            cout << max(first, second) << " ";
        }
        cout << psum[n] << endl;
        
    }
}
