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

typedef pair<ll, pii> node;
struct edge {
    int x, y;
    ll weight;
};

void add_edge(pii a, pii b, vector<vector<vector<edge>>> &edges) {
    edges[a.first][a.second].push_back({b.first, b.second, 1});
    edges[b.first][b.second].push_back({a.first, a.second, 1});
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;
    vvb lit(n + 1, vb(m + 1, false));
    while (k--) {
        int x, y;
        cin >> x >> y;
        lit[x][y] = true;
    }

    vector<vector<vector<edge>>> edges(n + 1, vector<vector<edge>>(m + 1));
    // use (0, j), (i, 0) as virtual nodes

    // base adjacencies
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            if (!lit[x][y])
                continue;

            int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (auto dd : d) {
                int new_x = x + dd[0];
                int new_y = y + dd[1];
                if (new_x < 1 || new_x > n || new_y < 1 || new_y > m)
                    continue;
                if (lit[new_x][new_y])
                    edges[x][y].push_back({new_x, new_y, 0});
            }
        }
    }

    // virtual node adjacencies
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (lit[i][j]) {
                edges[i][j].push_back({i, 0, 1});
                add_edge({i, j}, {i, 0}, edges);
                if (i - 1 >= 1)
                    add_edge({i, j}, {i - 1, 0}, edges);
                if (i + 1 <= n)
                    add_edge({i, j}, {i + 1, 0}, edges);

                add_edge({i, j}, {0, j}, edges);
                if (j - 1 >= 1)
                    add_edge({i, j}, {0, j - 1}, edges);
                if (j + 1 <= m)
                    add_edge({i, j}, {0, j + 1}, edges);
            }

            edges[i][0].push_back({i, j, 1});
            if (i - 1 >= 1)
                edges[i - 1][0].push_back({i, j, 1});
            if (i + 1 <= n)
                edges[i + 1][0].push_back({i, j, 1});

            edges[0][j].push_back({i, j, 1});
            if (j - 1 <= n)
                edges[0][j - 1].push_back({i, j, 1});
            if (j + 1 <= n)
                edges[0][j + 1].push_back({i, j, 1});
        }
    }

    // do dijkstra
    vvll dist(n + 1, vll(m + 1, LLONG_MAX));
    priority_queue<node, vector<node>, greater<node>> pq;
    dist[1][1] = 0;
    pq.push({0, {1, 1}});
    while (!pq.empty()) {
        node top = pq.top();
        pq.pop();
        ll cur_dist = top.first;
        int x = top.second.first;
        int y = top.second.second;
        if (cur_dist > dist[x][y]) {
            continue;
        }

        cout << "dfs at " << x << ", " << y << "!";
        cout << " dist = " << cur_dist << endl;

        for (edge e : edges[x][y]) {
            ll new_dist = cur_dist + e.weight;
            if (new_dist < dist[e.x][e.y]) {
                dist[e.x][e.y] = new_dist;
                pq.push({new_dist, {e.x, e.y}});
                cout << "pushing " << e.x << ", " << e.y << endl;
            }
        }
        cout << endl;
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << "edges at " << i << ", " << j << endl;
    //         for (edge e : edges[i][j]) {
    //             cout << "\t" << e.x << ", " << e.y << ": " << e.weight <<
    //             endl;
    //         }
    //     }
    // }

    if (dist[n][m] == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << dist[n][m] / 2 << endl;
    }
}
