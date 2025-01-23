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
        int n; cin >> n;
        vi l(n), r(n);
        map<int, int> m;
        vi psum(2 * n + 1);
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
            if (l[i] == r[i]) {
                m[l[i]]++;
            }
        }

        for (int i = 1; i < 2 * n + 1; i++) {
            if (m[i] == 0) {
                psum[i]++;
            }
            psum[i] += psum[i - 1];
        }

        for (int i = 0; i < n; i++) {
            if (l[i] == r[i] && m[l[i]] <= 1) {
                cout << 1;
                /*cout << 2;*/
                continue;
            }
            if (psum[r[i]] - psum[l[i] - 1] > 0) {
                cout << 1;
                continue;
            }
            cout << 0;
        }
        cout << endl;
    }
}
