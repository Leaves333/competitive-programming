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

struct edge {
    ll dest, weight;
};

int main() {
    ifstream fin("mootube.in");
    ofstream fout("mootube.out");

    int n, q;
    fin >> n >> q;
    vector<vector<edge>> edges(n + 1);
    for (int i = 0; i < n - 1; i++) {
        ll u, v, w;
        fin >> u >> v >> w;
        edges[u].push_back(edge {v, w});
        edges[v].push_back(edge {u, w});
    }

    while (q--) {
        ll k, v;
        fin >> k >> v;

        vb visited(n + 1, false);
        queue<pair<int, int>> qq; // relevance, location
        qq.push({INT_MAX, v});
        int ans = 0;

        while (!qq.empty()) {
            ll rel = qq.front().first;
            ll loc = qq.front().second;
            qq.pop();

            if (visited[loc])
                continue;

            ans++;
            visited[loc] = true;
            for (auto e : edges[loc]) {
                ll new_rel = min(rel, e.weight);
                if (new_rel >= k) {
                    qq.push({new_rel, e.dest});
                }
            }
        }

        fout << ans - 1 << endl;
    }
}
