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

    int n; cin >> n;
    vector<pii> bounds;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        bounds.push_back({x, y});
    }

    for (int i = n; i >= 0; i--) {
        int truth = 0;
        for (pii p : bounds) {
            if (i >= p.first && i <= p.second)
                truth++;
        }
        if (truth == i) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
