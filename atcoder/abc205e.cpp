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

    const int N = 2e6 + 50;
    vll factorial(N);
    factorial[0] = 1;
    for (int i = 1; i < N; i++) {
        factorial[i] = ( factorial[i - 1] * i ) % MOD;
    }

    int n, m, k;
    cin >> n >> m >> k;

    if (n > m + k) {
        cout << 0 << endl;
        return 0;
    }

    // (m + n) choose n total paths
    ll total = binom(m + n, n, factorial);

    // (m + n) choose (m + k + 1) bad paths
    ll bad = 0;
    if (k + 1 <= n)
        bad = binom(m + n, m + k + 1, factorial);

    ll ans = total - bad;
    if (ans < 0)
        ans += MOD;
    cout << ans << endl;

}
