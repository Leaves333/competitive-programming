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

    int n; cin >> n;
    vi p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    vb visited(n);
    vvi cycles;
    map<int, vi> even_pairings;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vi cycle;
            int cur = i;
            while (!visited[cur]) {
                visited[cur] = true;
                cycle.push_back(cur);
                cur = p[cur];
            }
            
            if (cycle.size() % 2 == 1) {
                vi square_root_cycle(cycle.size());
                for (int j = 0; j < cycle.size(); j++) {
                    square_root_cycle[(j*2) % cycle.size()] = cycle[j];
                }
                cycles.push_back(square_root_cycle);
            } else {
                if (even_pairings.count(cycle.size())) {
                    vi square_root_cycle(cycle.size() * 2);
                    vi other_cycle = even_pairings[cycle.size()];
                    for (int j = 0; j < cycle.size(); j++) {
                        square_root_cycle[(2*j)] = cycle[j];
                    }
                    for (int j = 0; j < cycle.size(); j++) {
                        square_root_cycle[(2*j) + 1] = other_cycle[j];
                    }
                    cycles.push_back(square_root_cycle);
                    even_pairings.erase(cycle.size());
                } else {
                    even_pairings[cycle.size()] = cycle;
                }
            }
        }
    }

    if (even_pairings.size() != 0) {
        cout << -1 << endl;
    } else {
        vi ans(n);
        for (vi cycle : cycles) {
            for (int i = 0; i < cycle.size(); i++) {
                ans[cycle[i]] = cycle[(i+1)%cycle.size()] + 1;
            }
        }
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
}
