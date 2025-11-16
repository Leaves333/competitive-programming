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

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pll> odd;
        vector<pll> even;
        for (int i = 0; i < k; i++) {
            ll x, y;
            cin >> x >> y;
            if ((x + y) % 2 == 1) {
                odd.push_back({x, y});
            } else {
                even.push_back({x, y});
            }
        }
    }
}
