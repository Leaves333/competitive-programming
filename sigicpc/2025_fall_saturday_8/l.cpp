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

#define UNCOLORED 0
#define RED 1
#define GREEN 2
#define BLUE 4

struct edge {
    int source, dest, idx, color;
};

void topsort(int x, vb &visited, vi &ordering, const vvi &edges) {
    if (visited[x])
        return;
    visited[x] = true;
    for (auto adj : edges[x]) {
        topsort(adj, visited, ordering, edges);
    }
    ordering.push_back(x);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vvi graph(n + 1);
    vector<edge> edges;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        edges.push_back({u, v, i, UNCOLORED});
    }

    vb visited(n + 1, false);
    vi ordering;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            topsort(i, visited, ordering, graph);
        }
    }
    reverse(ordering.begin(), ordering.end());

    vi pos(n + 1);
    for (int i = 0; i < n; i++) {
        pos[ordering[i]] = i;
    }
    sort(edges.begin(), edges.end(),
         [pos](const edge &lhs, const edge &rhs) {
             return pos[lhs.dest] < pos[rhs.dest];
         });

    vi color(n + 1);
    for (edge &e : edges) {
        if (!(color[e.source] & RED)) {
            e.color = RED;
            color[e.dest] |= RED;
        } else if (!(color[e.source] & GREEN)) {
            e.color = GREEN;
            color[e.dest] |= GREEN;
        } else {
            e.color = BLUE;
            color[e.dest] |= BLUE;
        }
    }

    sort(edges.begin(), edges.end(), [](const edge &lhs, const edge &rhs) {
        return lhs.idx < rhs.idx;
    });
    for (const edge &e : edges) {
        if (e.color == RED) {
            cout << 'R' << endl;
        } else if (e.color == GREEN) {
            cout << 'G' << endl;
        } else if (e.color == BLUE) {
            cout << 'B' << endl;
        }
    }

}
