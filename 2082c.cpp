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

const ll MOD = 1000000007;
ll pow_mod(ll x, ll n, ll m) {
    if (n == 0)
        return 1;
    ll t = pow_mod(x, n / 2, m);
    if (n % 2 == 0)
        return (t * t) % m;
    else
        return (((t * t) % m) * x) % m;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        ll one_half = pow_mod(2, MOD - 2, MOD);
        vll dp(n + 1);
        for (int i = 1; i <= n; i++) {
            if (s[n - i] == '0') {
                dp[i] = (one_half * dp[i-1]) % MOD;
            } else {
                dp[i] = (one_half * (1 - dp[i-1] + MOD) + dp[i-1]) % MOD;
            }
        }

        // for (auto x : dp) {
        //     cout << x << " ";
        // }
        // cout << endl;

        ll ans = n - 1 + dp[n - 1];
        cout << ans << endl;

    }
}
