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

    ll n, m;
    cin >> n >> m;

    vvi edges(n + 1);
    vll armies(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        cin >> armies[i + 1];
    }

    set<int> seen;
    priority_queue<pii, vector<pii>, greater<pii>> targets; // min heap

    // start at 1
    seen.insert(1);
    ll size = armies[1];
    for (auto dest : edges[1]) {
        if (!seen.count(dest)) {
            seen.insert(dest);
            targets.push({armies[dest], dest});
        }
    }

    while (!targets.empty()) {
        ll top_armies = targets.top().first;
        ll top_dest = targets.top().second;
        targets.pop();

        if (top_armies >= size)
            break;
        size += top_armies;

        for (auto dest : edges[top_dest]) {
            if (!seen.count(dest)) {
                seen.insert(dest);
                targets.push({armies[dest], dest});
            }
        }
    }

    cout << size << endl;
}
