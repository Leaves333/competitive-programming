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

    const int N = 2e6 + 10;
    vll factorial(N);
    factorial[0] = 1;
    for (int i = 1; i < N; i++) {
        factorial[i] = ( factorial[i - 1] * i ) % MOD;
    }

    int t; cin >> t;
    while (t--) {
        int a, b, n;
        cin >> n >> a >> b;
        vi p(a), s(b);
        for (int i = 0; i < a; i++) {
            cin >> p[i];
        }
        for (int i = 0; i < b; i++) {
            cin >> s[i];
        }

        if (p.back() != s.front() || p.front() != 1 || s.back() != n) {
            cout << 0 << endl;
            continue;
        }

    }
}
