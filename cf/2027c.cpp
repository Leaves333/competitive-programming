#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

ll dfs(ll x, set<ll> &visited, map<ll, vll> &edges) {
    visited.insert(x);
    ll ret = x;
    for (ll dest : edges[x]) {
        if (visited.count(dest))
            continue;
        ret = max(ret, dfs(dest, visited, edges));
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        map<ll, vll> edges;
        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            edges[x + i].push_back(x + i + i);
        }

        set<ll> visited;
        cout << dfs(n, visited, edges) << endl;
    }
}
