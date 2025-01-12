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
        int l, r;
        cin >> l >> r;

        int x = 0;
        for (int i = 30; i >= 0; i--) {
            if ((l & 1 << i) ^ (r & 1 << i)) {
                x += 1 << i;
                break;
            } else if ((l & 1 << i) & (r & 1 << i)) {
                x += 1 << i;
            }
        }
        int y = x - 1;
        int z = l;
        while (z == x || z == y) {
            z++;
        }
        cout << x << " " << y << " " << z << endl;
    }
}
