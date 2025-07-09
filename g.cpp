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

int mod(int x, int m) {
    return (x % m + m) % m;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;

        vi nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        // precompute factors of m
        set<int> factors_set;
        for (int i = 1; i * i <= m; i++) {
            if (m % i == 0) {
                factors_set.insert(i);
                factors_set.insert(m / i);
            }
        }

        vi factors(factors_set.begin(), factors_set.end());
        map<int, int> factor_to_index;
        for (int i = 0; i < factors.size(); i++) {
            factor_to_index[factors[i]] = i;
        }

        // precompute mods
        vvi mod_by_factor(factors.size(), vi(n + 1));
        for (int i = 0; i < factors.size(); i++) {
            for (int j = 1; j <= n; j++) {
                mod_by_factor[i][j] = nums[j - 1] % factors[i];
            }
        }

        // precompute sums
        vll sums(factors.size());
        for (int i = 0; i < factors.size(); i++) {
            for (int j = 1; j <= n; j++) {
                int a = mod_by_factor[i][j - 1];
                int b = mod_by_factor[i][j];
                sums[i] += mod(b - a, factors[i]);
            }
        }

        while (q--) {
            int op;
            cin >> op;
            if (op == 1) {
                int i, x;
                cin >> i >> x;
                nums[i - 1] = x;

                for (int f = 0; f < factors.size(); f++) {

                    // undo the old one...
                    int a = mod_by_factor[f][i - 1];
                    int b = mod_by_factor[f][i];
                    sums[f] -= mod(b - a, factors[f]);

                    if (i < n) {
                        a = mod_by_factor[f][i];
                        b = mod_by_factor[f][i + 1];
                        sums[f] -= mod(b - a, factors[f]);
                    }

                    // update with the new one
                    mod_by_factor[f][i] = nums[i - 1] % factors[f];

                    a = mod_by_factor[f][i - 1];
                    b = mod_by_factor[f][i];
                    sums[f] += mod(b - a, factors[f]);

                    if (i < n) {
                        a = mod_by_factor[f][i];
                        b = mod_by_factor[f][i + 1];
                        sums[f] += mod(b - a, factors[f]);
                    }
                }

            } else {
                int k;
                cin >> k;
                int f = gcd(m, k);
                // cout << "m, k, f: " << m << " " << k << " " << f << endl;
                if (sums[factor_to_index[f]] >= m) {
                    cout << "NO" << endl;
                } else {
                    cout << "YES" << endl;
                }
            }
        }
    }
}
