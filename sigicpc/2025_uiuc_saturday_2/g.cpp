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

struct ping {
    ll player, x, y, time;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int p, n;
    cin >> p >> n;
    vector<ping> pings(n);
    for (int i = 0; i < n; i++) {
        int p, x, y, t;
        cin >> p >> x >> y >> t;
        pings[i] = {p, x, y, t};
    }

    sort(pings.begin(), pings.end(),
         [](const ping &a, const ping &b) { return a.time < b.time; });

    set<pii> ans;
    deque<ping> dq;
    for (int i = 0; i < n; i++) {
        ping cur = pings[i];
        while (!dq.empty() && cur.time - dq.front().time > 10) {
            dq.pop_front();
        }
        for (const ping &other : dq) {
            if (cur.player == other.player)
                continue;
            ll x_diff = cur.x - other.x;
            ll y_diff = cur.y - other.y;
            ll dist = (x_diff * x_diff) + (y_diff * y_diff);
            if (dist <= 1000000)
                ans.insert({min(cur.player, other.player),
                            max(cur.player, other.player)});
        }
        dq.push_back(cur);
    }

    cout << ans.size() << endl;
    for (auto const &p : ans) {
        cout << p.first << " " << p.second << endl;
    }
}
