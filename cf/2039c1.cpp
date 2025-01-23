#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {

        ll x, m;
        cin >> x >> m;

        int ans = 0;
        for (int i = 1; i <= min(2 * x, m); i++) {
            if (x == i)
                continue;
            ll k = x ^ i;
            if (x % k == 0 || i % k == 0) {
                ans++;
            }
        }

        cout << ans << endl;
    }
}
