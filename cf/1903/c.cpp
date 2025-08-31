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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vll vals(n);
        for (int i = 0; i < n; i++) {
            cin >> vals[i];
        }

        vll psum(n + 1);
        for (int i = 1; i <= n; i++) {
            psum[i] = psum[i - 1] + vals[i - 1];
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (i + 1) * vals[i];
        }

        for (int i = n - 1; i > 0; i--) {
            ll diff = psum[n] - psum[i];
            if (diff < 0) {
                ans -= diff;
            }
        }

        cout << ans << endl;
    }
}
