#include <bits/stdc++.h>
#include <queue>
#include <utility>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

// dist, loc, prev
struct state {
    int dist;
    int location;
    int prev;
};

bool operator<(const state &first, const state &second) {
    return first.dist > second.dist;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;

    vvi edges(n+1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    map<pii, set<int>> bad;
    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        bad[make_pair(a, b)].insert(c);
    }

    vi dist(n+1, INT_MAX);
    vi parent(n+1, -1);

    priority_queue<state> pq;
    pq.push(state{0, 1, 0});
    dist[1] = 0;

    while (!pq.empty()) {
        state cur = pq.top();
        pq.pop();
        cout << "at cur=" << cur.location << ", prev=" << cur.prev << endl;
        for (int dest : edges[cur.location]) {
            if (bad[make_pair(cur.prev, cur.location)].count(dest))
                continue;
            if (dist[dest] <= cur.dist + 1)
                continue;
            dist[dest] = cur.dist + 1;
            parent[dest] = cur.location;
            pq.push(state{cur.dist + 1, dest, cur.location});
        }
    }

    if (dist[n] == INT_MAX) {
        cout << -1 << endl;
    } else {
        vi path;
        int cur = n;
        while (cur != -1) {
            path.push_back(cur);
            cur = parent[cur];
        }
        reverse(path.begin(), path.end());
        cout << path.size() - 1 << endl;
        for (int x : path) {
            cout << x << " ";
        }
        cout << endl;
    }

}
