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
        vi a(n), b(n), c(n), d(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i] >> c[i] >> d[i];
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            // if zeros need to be removed...
            if (a[i] > c[i]) {
                ans += a[i] - c[i];
            }

            // if ones need to be removed...
            if (b[i] > d[i]) {
                ans += min(a[i], c[i]); // move zeros out
                ans += b[i] - d[i]; // move ones
            }
            // cout << "calculated " << i << ", ans is " << ans << endl;
        }
        
        cout << ans << endl;
    }
}
