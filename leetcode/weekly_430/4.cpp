#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pow_mod(long long x, long long n, long long m) {
        if (n == 0)
            return 1;
        long long t = pow_mod(x, n / 2, m);
        if (n % 2 == 0) {
            return (t * t) % m;
        } else {
            return (((t * t) % m) * x) % m;
        }
    }

    long long factorial(long long n, long long m) {
        long long val = 1;
        for (int i = 1; i <= n; i++) {
            val *= i;
            val %= m;
        }
        return val;
    }

    int countGoodArrays(int n, int m, int k) {

        if (k == n - 1) {
            return m;
        }

        const long long MOD = 1000000007;
        long long segments = n - k;
        long long ans = m * pow_mod((m - 1), (segments - 1), MOD);
        ans %= MOD;

        cout << "base: " << ans << endl;
        cout << "segments: " << segments << endl;

        // n - 1 choose k
        long long num = factorial(n - 1, MOD);
        long long denom = factorial(k, MOD);
        denom *= factorial(n - 1 - k, MOD);
        denom %= MOD;

        cout << "num: " << num << endl;
        cout << "denom: " << denom << endl;

        ans *= num;
        long long inverse = pow_mod(denom, MOD - 2, MOD);
        cout << "inverse: " << inverse << endl;
        ans %= MOD;
        ans *= pow_mod(denom, MOD - 2, MOD);

        return ans % MOD;
    }
};
