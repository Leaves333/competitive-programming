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

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vll a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        sort(b.begin(), b.end());
        a[0] = min(a[0], b[0] - a[0]);

        // return smallest value of b s.t. b-a[i] >= a[i-1] -> b >= a[i-1]+a[i]
        for (int i = 1; i < n; i++) {
            auto it = lower_bound(b.begin(), b.end(), a[i - 1] + a[i]);
            if (it == b.end())
                continue;
            ll val = *it - a[i];
            if (a[i] < a[i-1])
                a[i] = val;
            else
                a[i] = min(a[i], val);
        }

        bool good = true;
        for (int i = 1; i < n; i++)
            if (a[i] < a[i - 1])
                good = false;

        if (good)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
