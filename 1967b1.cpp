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

    int t; cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;

        // gcd(a, b) * b * n = a + b for some n
        // => a + b is a multiple of b
        // => a is a multiple of b
        // with the constraint that a > (b - 1) * b

        ll ans = 0;
        for (ll i = 1; i <= b; i++) {
            ll smallest_a = (i - 1) * i;
            ll combs = max(a - smallest_a, 0ll) / i;
            ans += combs;
            cout << i << ": " << combs << endl;
        }
        cout << ans << endl;
    }
}
