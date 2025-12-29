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

const int p = 127;
const int q = 131;
const ll MOD = 1e9 + 7;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;

    ll forward_p_hash = 0;
    ll forward_q_hash = 0;
    ll backward_p_hash = 0;
    ll backward_q_hash = 0;

    ll p_pow = 1;
    ll q_pow = 1;

    ll ans = 0;
    vi dp(s.length() + 1);
    for (int i = 0; i < s.length(); i++) {
        forward_p_hash += s[i] * p_pow;
        forward_q_hash += s[i] * q_pow;
        forward_p_hash %= MOD;
        forward_q_hash %= MOD;
        p_pow = (p_pow * p) % MOD;
        q_pow = (q_pow * q) % MOD;

        backward_p_hash *= p;
        backward_q_hash *= q;
        backward_p_hash += s[i];
        backward_q_hash += s[i];
        backward_p_hash %= MOD;
        backward_q_hash %= MOD;

        if (forward_p_hash == backward_p_hash) {
            dp[i+1] = dp[(i+1)/2] + 1;
        }
        ans += dp[i+1];
    }

    cout << ans << endl;
}
