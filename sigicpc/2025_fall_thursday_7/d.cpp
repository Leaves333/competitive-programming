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

const ll MOD = 998244353;

ll pow_mod(ll x, ll n) {
    if (n == 0)
        return 1;
    ll t = pow_mod(x, n / 2);
    if (n % 2 == 0)
        return (t * t) % MOD;
    else
        return (((t * t) % MOD) * x) % MOD;
}

// computs n choose k
ll binom(ll n, ll k, const vll &factorial) {
    ll ret = factorial[n];
    ret *= pow_mod(factorial[k], MOD - 2);
    ret %= MOD;
    ret *= pow_mod(factorial[n - k], MOD - 2);
    ret %= MOD;
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    const int N = 100;
    vll factorial(N);
    factorial[0] = 1;
    for (int i = 1; i < N; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        n /= 2;

        vll dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        if (n >= 2) {
            dp[2] = 3;
        }
        for (int i = 3; i <= n; i++) {
            // ways to win if a has the biggest
            dp[i] += binom(2 * i - 1, i - 1, factorial);
            // ways to win if a doesn't have the biggest
            dp[i] += binom(2 * (i - 1), i - 1, factorial) - dp[i - 1] - 1;
            dp[i] += 3 * MOD;
            dp[i] %= MOD;
        }

        ll a = dp[n];
        ll c = 1;
        ll b = ((3 * MOD) + binom(n * 2, n, factorial) - a - c) % MOD;

        cout << a << " " << b << " " << c << endl;
    }
}
