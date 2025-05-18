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
        vvi arr(n, vi(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }

        vb seen(2000);
        vi perm(2 * n);
        for (int i = 0; i < n; i++) {
            perm[i + 1] = arr[0][i];
            seen[perm[i + 1]] = true;
        }

        for (int i = 1; i < n; i++) {
            perm[n + i] = arr[n-1][i];
            seen[perm[n + i]] = true;
        }

        for (int i = 1; i < seen.size(); i++) {
            if (!seen[i]) {
                perm[0] = i;
                break;
            }
        }

        for (int x : perm) {
            cout << x << " ";
        }
        cout << endl;
    }
}
