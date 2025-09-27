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
        ll n, m, x, y;
        cin >> n >> m >> x >> y;

        vll a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vll b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        cout << n + m << endl;
    }
}
