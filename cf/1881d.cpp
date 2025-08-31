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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    const int N = 1000001;
    vb sieve(N, true);
    for (int i = 2; i < N; i++) {
        if (sieve[i]) {
            for (int j = i + i; j < N; j += i) {
                sieve[j] = false;
            }
        }
    }

    set<int> primes;
    for (int i = 2; i < N; i++) {
        if (sieve[i])
            primes.insert(i);
    }

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        map<int, int> count;
        for (int &num : nums) {
            if (primes.count(num)) {
                count[num]++;
                continue;
            }

            for (int i = 2; num > 1; i++) {
                while (num % i == 0) {
                    num /= i;
                    count[i]++;
                }
            }
        }

        bool good = true;
        for (const auto &[key, val] : count) {
            if (val % n != 0) {
                good = false;
            }
        }

        if (good)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
