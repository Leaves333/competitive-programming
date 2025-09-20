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
        ll x, y;
        cin >> x >> y;
        if (y > x) {
            cout << 2 << endl;
        } else if (y > 1 && x >= y + 2) {
            // 1, then y, then y + 1.
            cout << 3 << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
