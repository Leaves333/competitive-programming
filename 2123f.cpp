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

    const int N = 100001;
    vb is_prime(N, false);

    vi primes;
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vi ans(n + 1);
        vb used(n + 1, false);

        for (int p : primes) {
        }

        // set first val
        ans[1] = 1;
        used[1] = true;

        for (int i = 1; i <= n; i++) {
            cout << ans[i] << endl;
        }
    }
}
