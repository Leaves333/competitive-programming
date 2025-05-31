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

map<int, int> prime_factorize(int x, const vi &primes) {
    map<int, int> res;
    for (int p : primes) {
        while (x % p == 0) {
            x /= p;
            res[p]++;
        }
    }
    return res;
}

set<int> factorize(int x) {
    set<int> res;
    for (int i = 1; i <= sqrt(x) + 1; i++) {
        if (x % i == 0) {
            res.insert(i);
            res.insert(x / i);
        }
    }
    return res;
}

int find_steps(int x, const int k) {

    set<int> factors_set = factorize(x);
    vi factors(factors_set.begin(), factors_set.end());
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

    // cout << "here's factors: ";
    // for (auto x : factors) {
    //     cout << x << " ";
    // }
    // cout << endl;
    // cout << "here's dp: ";
    // for (auto x : dp) {
    //     cout << x << " ";
    // }
    // cout << endl;

    return dp.back();
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
        map<int, int> x_factors = prime_factorize(x, primes);
        map<int, int> y_factors = prime_factorize(y, primes);

        bool good = true;
        map<int, int> factor_difference;
        for (int i = 0; i < primes.size(); i++) {
            int p = primes[i];
            factor_difference[p] = x_factors[p] - y_factors[p];
            if (p > k && factor_difference[p] != 0) {
                good = false;
                break;
            }
        }
        
        if (!good) {
            cout << -1 << endl;
            continue;
        }

        ll pos_product = 1;
        ll neg_product = 1;
        for (auto p : factor_difference) {
            if (p.second > 0) {
                pos_product *= pow(p.first, p.second);
            } else if (p.second < 0) {
                neg_product *= pow(p.first, -1 * p.second);
            }
        }
        
        int ans = 0;
        ans += find_steps(pos_product, k);
        ans += find_steps(neg_product, k);

        cout << ans << endl;

    }
}
