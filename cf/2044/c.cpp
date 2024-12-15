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

    int t; cin >> t;
    while (t--) {
        int m, a, b, c;
        cin >> m >> a >> b >> c;
        ll ans = 0;
        ans += min(m, a) + min(m, b);
        ans += min((2 * m) - min(m, a) - min(m, b), c);
        cout << ans << endl;
    }
}
