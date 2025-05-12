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
        pll max_top = {1, 1}, max_bottom = {1, 1};
        while (n--) {
            char a, b;
            ll x, y;
            cin >> a >> x >> b >> y;

            ll top_to_add = 0;
            ll bottom_to_add = 0;
            if (a == '+') {
                top_to_add += x;
                bottom_to_add += x;
            } else {
                top_to_add += (x - 1) * max_top.first;
                bottom_to_add += (x - 1) * max_bottom.first;
            }

            if (b == '+') {
                top_to_add += y;
                bottom_to_add += y;
            } else {
                top_to_add += (y - 1) * max_top.second;
                bottom_to_add += (y - 1) * max_bottom.second;
            }


        }

        cout << max(max_top.first + max_top.second, max_bottom.first + max_bottom.second) << endl;
    }
}
