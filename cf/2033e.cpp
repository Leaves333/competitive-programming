#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int dfs(int pos, vi& dest, vector<bool>& visited) {
    int ct = 1;
    visited[pos] = true;
    if (!visited[dest[pos]]) {
        ct += dfs(dest[pos], dest, visited);
    }
    return ct;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi dest(n);
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            cin >> dest[i];
            dest[i]--;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int sz = dfs(i, dest, visited);
                ans += (sz - 1) / 2;
            }
        }
        cout << ans << endl;
    }
}
