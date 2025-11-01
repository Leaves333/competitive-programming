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

vi primes;
int solve(int x, int k, vi &dp) {

    // cout << "solve: " << x << " " << k << endl;

    if (dp[x] != -1)
        return dp[x];
    if (x <= k)
        return dp[x] = 1;

    int cur = x;
    map<int, int> factors;
    for (int p : primes) {
        if (p > x)
            break;
        if (p > k)
            return -1;
        while (x % p == 0) {
            x /= p;
            factors[p]++;
        }
    }

    int smol = INT_MAX;
    for (int i = 1; (ll)i * i <= x; i++) {
        if (x % i == 0) {
            if (x / i < k)
                smol = min(smol, solve(x / i, k, dp) + 1);
            if (i < k)
                smol = min(smol, solve(i, k, dp) + 1);
        }
    }
    return dp[x] = smol;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    const int LIMIT = 100001;
    vb is_prime(LIMIT, true);
    for (int i = 2; i < LIMIT; i++) {
        if (!is_prime[i])
            continue;
        primes.push_back(i);
        for (int j = i; j < LIMIT; j += i) {
            is_prime[j] = false;
        }
    }

    int t;
    cin >> t;
    vi dp;
    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;
        int g = gcd(x, y);

        dp.assign(x / g + 1, -1);
        dp[1] = 0;
        int first = solve(x / g, k, dp);

        dp.assign(y / g + 1, -1);
        dp[1] = 0;
        int second = solve(y / g, k, dp);

        if (first == -1 || second == -1)
            cout << -1 << endl;
        else
            cout << first + second << endl;
    }
}
