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
        ll n;
        cin >> n;
        ll px, py, qx, qy;
        cin >> px >> py >> qx >> qy;
        vll a(n);
        ll max_dist = 0;
        ll max_step = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            max_dist += a[i];
            max_step = max(max_step, a[i]);
        }

        ll dist = (px - qx) * (px - qx) + (py - qy) * (py - qy);
        if (dist > max_dist * max_dist) {
            cout << "No" << endl;
            continue;
        }

        ll min_dist = max(0ll, max_step - (max_dist - max_step));
        if (dist < min_dist * min_dist) {
            cout << "No" << endl;
            continue;
        }

        if (n >= 3) {
            cout << "Yes" << endl;
            continue;
        }

        if (n == 2) {
            if (px == qx && py == qy) {
                if (a[0] == a[1]) {
                    cout << "Yes" << endl;
                    continue;
                } else {
                    cout << "No" << endl;
                    continue;
                }
            } else {
                cout << "Yes" << endl;
                continue;
            }
        }

        if (n == 1) {
            ll first = a[0] * a[0];
            if (first == dist) {
                cout << "Yes" << endl;
                continue;
            }
        }

        cout << "No" << endl;
    }
}
