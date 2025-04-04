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
        int n; cin >> n;

        // for any n, decompose as a sum of n^2 - n
        vector<pii> staff_locs;

        int x = 0, y = 0;
        while (n > 0) {
            int k = 0;
            while (((k + 1) * k / 2) <= n) {
                k++;
                staff_locs.push_back({x, y});
                x++;
            }
            y++;
            n -= ((k - 1) * k) / 2;
            /*cout << "n=" << n << ", k=" << k << endl;*/
        }

        cout << staff_locs.size() << endl;
        for (auto p : staff_locs) {
            cout << p.first << " " << p.second << endl;
        }
    }
}
