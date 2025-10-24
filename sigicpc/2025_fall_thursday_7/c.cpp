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

const int MOD = 1e9 + 7;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        // looks like 1111, ..., 1111, 0000
        // oh. we need to distribute the k zeros among the n elements.

        ll ans = 1;
        for (int i = 0; i < k; i++) {
            ans *= n;
            ans %= MOD;
        }
        cout << ans << endl;
    }
}
