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

vll factorize(ll x) {
    vll res;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            res.push_back(i);
            if (i != x / i)
                res.push_back(x / i);
        }
    }
    return res;
}

int find_steps(int x, const int k) {

    vll factors = factorize(x);
    sort(factors.begin(), factors.end());
    vll dp(factors.size(), INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < factors.size(); i++) {
        int cur = factors[i];
        for (int j = i - 1; j >= 0; j--) {
            int div = factors[j];
            if (cur / div > k)
                break;
            if (cur % div != 0)
                continue;
            dp[i] = min(dp[i], dp[j] + 1);
        }
    }

    return (dp.back() >= INT_MAX) ? -1 : dp.back();

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    const int N = 1000001;
    vb sieve(N, true);
    for (ll i = 2; i < N; i++) {
        if (sieve[i]) {
            for (ll j = i * i; j < N; j += i) {
                sieve[j] = false;
            }
        }
    }

    vi primes;
    for (int i = 2; i < N; i++) {
        if (sieve[i])
            primes.push_back(i);
    }

    int t; cin >> t;
    while (t--) {

        int x, y, k;
        cin >> x >> y >> k;

        int d = gcd(x, y);
        x /= d;
        y /= d;
        
        int ans_x = find_steps(x, k);
        int ans_y = find_steps(y, k);
        
        if (ans_x == -1 || ans_y == -1)
            cout << -1 << endl;
        else
            cout << ans_x + ans_y << endl;

    }
}
