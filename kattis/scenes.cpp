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

const ll MOD = 1e9 + 7;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, w, h;
    cin >> n >> w >> h;

    // dp[i][j] stores how many ways to use j inches with i slices
    vvll dp(w + 1, vll(n + 1, 0));

    // base case
    for (int i = 0; i <= min(h, n); i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= w; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = j; k >= max(0ll, j - h); k--) {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= MOD;
            }
        }
    }

    ll sum = 0;
    for (int i = 0; i < n + 1; i++) {
        sum += dp[w][i];
        sum %= MOD;
    }

    ll sub = 0;
    for (int i = 0; i <= h; i++) {
        if (i * w <= n)
            sub++;
        else
            break;
    }

    cout << (sum - sub + MOD) % MOD << endl;
}
