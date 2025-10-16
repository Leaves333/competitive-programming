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

struct edge {
    ll dest;
    ll weight;
};

struct state {
    ll pos;
    ll dist;
    bool has_horse;
};

bool operator>(const state &a, const state &b) { return a.dist > b.dist; }

void dijkstra(const vb &horse, vll &dist_walking, vll &dist_horse,
              priority_queue<state, vector<state>, greater<state>> &pq,
              const vector<vector<edge>> &edges) {
    while (!pq.empty()) {
        state cur = pq.top();
        pq.pop();

        if (cur.has_horse && cur.dist > dist_horse[cur.pos])
            continue;
        if (!cur.has_horse && cur.dist > dist_walking[cur.pos])
            continue;

        if (horse[cur.pos])
            cur.has_horse = true;

        for (edge e : edges[cur.pos]) {
            ll new_dist = cur.dist;
            if (cur.has_horse)
                new_dist += e.weight / 2;
            else
                new_dist += e.weight;

            if (cur.has_horse) {
                if (new_dist < dist_horse[e.dest]) {
                    dist_horse[e.dest] = new_dist;
                    pq.push({e.dest, new_dist, cur.has_horse});
                }
            } else {
                if (new_dist < dist_walking[e.dest]) {
                    dist_walking[e.dest] = new_dist;
                    pq.push({e.dest, new_dist, cur.has_horse});
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, m, h;
        cin >> n >> m >> h;
        vb horse(n + 1, false);
        for (int i = 0; i < h; i++) {
            int x;
            cin >> x;
            horse[x] = true;
        }

        vector<vector<edge>> edges(n + 1);
        for (int i = 0; i < m; i++) {
            ll u, v, w;
            cin >> u >> v >> w;
            edges[u].push_back({v, w});
            edges[v].push_back({u, w});
        }

        priority_queue<state, vector<state>, greater<state>> pq;
        vll dist_walking(n + 1, LLONG_MAX);
        vll dist_horse(n + 1, LLONG_MAX);
        dist_walking[1] = 0;
        pq.push({1, 0, false});
        dijkstra(horse, dist_walking, dist_horse, pq, edges);

        vll first(n + 1);
        for (int i = 0; i <= n; i++) {
            first[i] = min(dist_walking[i], dist_horse[i]);
        }

        dist_walking.assign(n + 1, LLONG_MAX);
        dist_horse.assign(n + 1, LLONG_MAX);
        dist_walking[n] = 0;
        pq.push({n, 0, false});
        dijkstra(horse, dist_walking, dist_horse, pq, edges);

        vll second(n + 1);
        for (int i = 0; i <= n; i++) {
            second[i] = min(dist_walking[i], dist_horse[i]);
        }

        ll ans = LLONG_MAX;
        for (int i = 0; i <= n; i++) {
            ans = min(ans, max(first[i], second[i]));
        }

        cout << (ans == LLONG_MAX ? -1 : ans) << endl;
    }
}
