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

struct dist {
    ll time, wait;
};

bool operator<(const dist &lhs, const dist &rhs) {
    if (lhs.time == rhs.time)
        return lhs.wait < rhs.wait;
    return lhs.time < rhs.time;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vvi edges(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        typedef pair<dist, ll> dist_pair;
        priority_queue<dist_pair, vector<dist_pair>, greater<dist_pair>> pq;
        vector<dist> min_time(n + 1, dist{LLONG_MAX, LLONG_MAX});
        vector<dist> min_wait(n + 1, dist{LLONG_MAX, LLONG_MAX});

        min_time[1] = {0, 0};
        min_wait[1] = {0, 0};
        pq.push({{0, 0}, 1}); // , index
        
        while (!pq.empty()) {

            dist cur_dist = pq.top().first;
            ll cur_time = cur_dist.time;
            ll cur_wait = cur_dist.wait;
            ll idx = pq.top().second;
            pq.pop();

            // cout << "dijkstras at " << idx << ", ";
            // cout << "time=" << cur_time;
            // cout << ", wait=" << cur_wait << endl;

            for (int k = 0; k < edges[idx].size(); k++) {
                int dest = edges[idx][k];
                int m = edges[idx].size();
                ll waiting_time = (cur_time % m <= k) ? k - (cur_time % m) : k - (cur_time % m) + m;

                ll dest_time = cur_time + waiting_time + 1;
                ll dest_wait = cur_wait + waiting_time;

                if (dest_time < min_time[dest].time) {
                    min_time[dest].time = dest_time;
                    min_time[dest].wait = dest_wait;
                    // cout << "pushing: time, wait, dest = " << dest_time << ", " << dest_wait << ", " << dest << endl;
                    pq.push({{dest_time, dest_wait}, dest});
                } else if (dest_time == min_time[dest].time && dest_wait < min_time[dest].wait) {
                    min_time[dest].wait = dest_wait;
                    // cout << "pushing: time, wait, dest = " << dest_time << ", " << dest_wait << ", " << dest << endl;
                    pq.push({{dest_time, dest_wait}, dest});
                }

                int dest_mod = edges[dest].size();
                if (dest_wait < min_wait[dest].wait) {
                    min_wait[dest].time = dest_time;
                    min_wait[dest].wait = dest_wait;
                    // cout << "pushing: time, wait, dest = " << dest_time << ", " << dest_wait << ", " << dest << endl;
                    pq.push({{dest_time, dest_wait}, dest});
                } else if (dest_wait == min_wait[dest].wait && (dest_time > min_wait[dest].time) && (dest_time < min_wait[dest].time + dest_mod)) {
                    min_wait[dest].time = dest_time;
                    // cout << "pushing: time, wait, dest = " << dest_time << ", " << dest_wait << ", " << dest << endl;
                    pq.push({{dest_time, dest_wait}, dest});
                }

            }
        }

        cout << min_time[n].time << " " << min_time[n].wait << endl;

    }
}
