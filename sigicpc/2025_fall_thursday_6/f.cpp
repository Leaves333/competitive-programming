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

// constants for hashing
const int MOD = 1e9 + 9;
const int p = 31, q = 53;
const int N = 1000001;

// precompute powers of p and q
vll p_pow(N);
vll q_pow(N);
vll p_inverse(N);
vll q_inverse(N);

// precompute hashes of prefixes
vll p_prefix;
vll q_prefix;

ll pow_mod(ll x, ll n) {
    if (n <= 0)
        return 1;
    ll t = pow_mod(x, n / 2);
    if (n % 2 == 1)
        return (((t * t) % MOD) * x) % MOD;
    else
        return (t * t) % MOD;
}

ll prefix_hash(int start, int len) {
    ll p_hash = p_prefix[start + len] - p_prefix[start];
    if (p_hash < 0)
        p_hash += MOD;
    p_hash = (p_hash * p_inverse[start]) % MOD;

    ll q_hash = q_prefix[start + len] - q_prefix[start];
    if (q_hash < 0)
        q_hash += MOD;
    q_hash = (q_hash * q_inverse[start]) % MOD;

    return p_hash | (q_hash << 32);
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s, t;
    cin >> s >> t;

    // precompute powers of p and q
    p_pow[0] = 1;
    q_pow[0] = 1;
    for (int i = 1; i <= s.length(); i++) {
        p_pow[i] = (p_pow[i-1] * p) % MOD;
        q_pow[i] = (q_pow[i-1] * q) % MOD;
    }

    for (int i = 0; i <= s.length(); i++) {
        p_inverse[i] = pow_mod(p_pow[i], MOD - 2);
        q_inverse[i] = pow_mod(q_pow[i], MOD - 2);
    }

    // precompute hashes of prefixes
    p_prefix.assign(s.length() + 1, 0);
    q_prefix.assign(s.length() + 1, 0);
    for (int i = 0; i < s.length(); i++) {
        p_prefix[i + 1] = (p_prefix[i] + (s[i] - 'a' + 1) * p_pow[i]) % MOD;
        q_prefix[i + 1] = (q_prefix[i] + (s[i] - 'a' + 1) * q_pow[i]) % MOD;
    }

    ll target_p = 0, target_q = 0;
    for (int i = 0; i < t.length(); i++) {
        target_p += (t[i] - 'a' + 1) * p_pow[i];
        target_p %= MOD;
        target_q += (t[i] - 'a' + 1) * q_pow[i];
        target_q %= MOD;
    }
    ll target_hash = target_p | (target_q << 32);

    vi ans;
    for (int i = 0; i < s.length(); i++) {
        ll left_p = p_prefix[i];
        ll right_p = p_prefix[s.length()] - p_prefix[i + 1] + MOD;
        ll left_q = q_prefix[i];
        ll right_q = q_prefix[s.length()] - q_prefix[i + 1] + MOD;
        ll p_hash = (left_p + (p_inverse[1] * right_p)) % MOD;
        ll q_hash = (left_q + (q_inverse[1] * right_q)) % MOD;
        ll hash = p_hash | (q_hash << 32);
        if (hash == target_hash) {
            ans.push_back(i + 1);
        }
    }

    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
}
