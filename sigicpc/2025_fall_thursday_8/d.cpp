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

    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vi a(n);
        vi b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        vll dp_swap(n);
        vll dp_no_swap(n);
        dp_swap[0] = 1;
        dp_no_swap[0] = 1;

        for (int i = 1; i < n; i++) {
            if (a[i] >= a[i-1] && b[i] >= b[i-1]) {
                dp_swap[i] += dp_swap[i-1];
                dp_no_swap[i] += dp_no_swap[i-1];
            }
            if (a[i] >= b[i-1] && b[i] >= a[i-1]) {
                dp_swap[i] += dp_no_swap[i-1];
                dp_no_swap[i] += dp_swap[i-1];
            }
            dp_swap[i] %= MOD;
            dp_no_swap[i] %= MOD;
        }
        cout << (dp_swap.back() + dp_no_swap.back()) % MOD << endl;
    }
}
