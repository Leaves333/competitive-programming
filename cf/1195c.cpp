#include <algorithm>
#include <iostream>
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

    int n;
    cin >> n;
    vvll heights(2, vll(n));
    for (int i = 0; i < n; i++) {
        cin >> heights[0][i];
    }
    for (int i = 0; i < n; i++) {
        cin >> heights[1][i];
    }

    vvll dp(2, vll(n));
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            dp[0][i] = heights[0][i];
            dp[1][i] = heights[1][i];
        } else if (i == 1) {
            dp[0][i] = heights[0][i] + dp[1][i - 1];
            dp[1][i] = heights[1][i] + dp[0][i - 1];
        } else {
            dp[0][i] = heights[0][i] + max(max(dp[1][i-1], dp[0][i-2]), dp[1][i-2]);
            dp[1][i] = heights[1][i] + max(max(dp[0][i-1], dp[1][i-2]), dp[0][i-2]);
        }
    }
    ll ans = max(dp[0][n - 1], dp[1][n - 1]);
    if (n > 1) {
        ans = max(ans, max(dp[0][n - 2], dp[1][n - 2]));
    }
    cout << ans << endl;
}
