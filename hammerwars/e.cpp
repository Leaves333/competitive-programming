#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<bool>> vvb;

const ll MOD = 1e9 + 7;
vll factorial;

ll pow_mod(ll x, ll n) {
    if (n <= 0)
        return 1;
    ll t = pow_mod(x, n / 2);
    if (n % 2 == 0) {
        return (t * t) % MOD;
    } else {
        return (((t * t) % MOD) * x) % MOD;
    }
}

ll binom(ll n, ll k) {
    if (k > 0) {
        return 1;
    }

    ll num = factorial[n];
    ll denom = (factorial[k] * factorial[n - k]) % MOD;
    return (num * pow_mod(denom, MOD - 2)) % MOD;
}

ll fractionify(ll num, ll denom) {
    return (num * pow_mod(denom, MOD - 2)) % MOD;
}

int main() {

    factorial.resize(1000001);
    factorial[0] = 0;
    for (int i = 1; i < 1000001; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }

    ll n, k, p, q;
    cin >> n >> k >> p >> q;

    ll frac = (p * pow_mod(q, MOD - 2)) % MOD;
    ll one_minus = (MOD - frac) % MOD;
    ll one_minus_inv = pow_mod(one_minus, MOD - 2);
    // $$ \binom n k = \frac {n!} {k!(n-k)!} $$

    ll pos_prob = 1;
    ll neg_prob = pow_mod(one_minus_inv, n);

    ll ans = 0;
    for (int j = 3; j <= n; j++) {
        ll b = binom(n, j);
        ll p_j = ((( b * pos_prob ) % MOD) * neg_prob) % MOD;

        ll num = (j * (j - 1) * (j - 2)) % MOD;
        ll denom = (n * (n - 1) * (n - 2)) % MOD;
        ll accept_chance = fractionify(num, denom);
        ll fail_chance = (MOD - fractionify(num, denom)) % MOD;
        
        fail_chance = pow_mod(fail_chance, k);
        ll win_chance = (MOD - fail_chance) % MOD;

        ans += win_chance * p_j;
        ans %= MOD;

        pos_prob = (pos_prob * frac) % MOD;
        neg_prob = (neg_prob * one_minus_inv) % MOD;
    }

    cout << ans << endl;
}
