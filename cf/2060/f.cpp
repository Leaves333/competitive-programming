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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    const int N = 100001;
    vb sieve(N, true);
    for (int i = 2; i < N; i++) {
        if (sieve[i]) {
            for (int j = i + i; j < N; j += i) {
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
        int n, k;
        cin >> n >> k;
    }
}
