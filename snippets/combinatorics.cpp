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

// computes x^n mod MOD
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
