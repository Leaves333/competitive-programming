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

    int t;
    cin >> t;
    while (t--) {
        ll n, l, r, k;
        cin >> n >> l >> r >> k;

        if (n % 2 == 1) {
            cout << l << endl;
        } else {
            // choose a, b that share no common bits?
            if ((__builtin_clzll(l) == __builtin_clzll(r)) || (l == r) ||
                (n == 2)) {
                cout << -1 << endl;
                continue;
            }

            if (k <= n - 2) {
                cout << l << endl;
            } else {
                ll ans = 1;
                while (ans <= l) {
                    ans <<= 1;
                }
                cout << ans << endl;
            }
        }
    }
}
