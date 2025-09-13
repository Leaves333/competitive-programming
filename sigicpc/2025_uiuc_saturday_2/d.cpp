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

struct order {
    int a, b, idx, ans;
};

void dfs(int x, const vvi &edges, set<int> &visited,
         vector<vector<order>> &orders) {

    for (auto &order : orders[x]) {
        if (visited.count(order.b)) {
            order.ans = 0;
        } else {
            order.ans = 1;
        }
    }

    visited.insert(x);
    for (const auto dest : edges[x]) {
        if (visited.count(dest))
            continue;
        dfs(dest, edges, visited, orders);
    }

    visited.erase(x);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vvi edges(n + 1);
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        edges[i].push_back(x);
        edges[x].push_back(i);
    }

    vector<vector<order>> orders(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        orders[a].push_back({a, b, i, -1});
    }

    // solve
    set<int> visited;
    dfs(1, edges, visited, orders);

    vector<order> all_orders;
    for (const auto &v : orders) {
        all_orders.insert(all_orders.end(), v.begin(), v.end());
    }
    sort(all_orders.begin(), all_orders.end(),
         [](const order &a, const order &b) { return a.idx < b.idx; });

    for (auto &order : all_orders) {
        if (order.ans == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
