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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vll vals;
        for (int i = 0; i < 62; i++) {
            ll mask = 1ll << i;
            if (n & mask) {
                vals.push_back(n - mask);
            }
        }

        reverse(vals.begin(), vals.end());
        if (vals.size() == 1) {
            cout << 1 << endl;
            cout << n << endl;
        } else {
            cout << vals.size() + 1 << endl;
            for (auto x : vals) {
                cout << x << " ";
            }
            cout << n << endl;
        }
    }
}
