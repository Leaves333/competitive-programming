#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

void build(vi t, vi a, int v, int tl, int tr) {
    cout << "build: " << v << " " << tl << " " << tr << endl;
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(t, a, v*2, tl, tm);
        build(t, a, v*2+1, tm+1, tr);
        t[v] = gcd(t[v*2], t[v*2+1]);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    // segment tree type thing to store gcd of segments of arr

    int t; cin >> t;
    while (t--) {

        int n, q;
        cin >> n >> q;
        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        if (n == 1) {
            cout << 0 << endl;
            continue;
        }

        vi differences(n - 1);
        for (int i = 0; i < n - 1; i++) {
            differences[i] = abs(arr[i] - arr[i + 1]);
        }

        vi tree(4 * n);
        build(tree, differences, 1, 0, n - 2);

        for (auto x : tree) {
            cout << x << " ";
        }
        cout << endl;

        while (q--) {
            int l, r;
            cin >> l >> r;
        }
    }
}
