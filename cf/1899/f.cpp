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
        int n, q;
        cin >> n >> q;

        for (int i = 1; i < n; i++) {
            cout << i << " " << i + 1 << endl;
        }

        int last_len = n - 1;
        while (q--) {

            int k; cin >> k;
            if (k == last_len) {
                cout << "-1 -1 -1" << endl;
                continue;
            }

            cout << n << " " << last_len << " " << k << endl;
            last_len = k;

        }
    }
}
