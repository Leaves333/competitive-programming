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

int dfs(int x, const vvi &edges, vb &visited, vi &children, vi &ordering) {
    visited[x] = true;
    int count = 1;
    for (auto dest : edges[x]) {
        if (visited[dest])
            continue;
        count += dfs(dest, edges, visited, children, ordering);
    }
    ordering.push_back(x);
    children[x] = count;
    return count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vvi edges(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        vb visited(n, false);
        vi children(n);
        vi ordering;
        dfs(0, edges, visited, children, ordering);

        // binary search on x?
        int low = 0, high = n;
        while (low < high) {

            int mid = low + (high - low + 1) / 2;

            vi lazy(n);
            int splits = 0;
            for (int x : ordering) {

                // update lazy prop for this node
                for (auto adj : edges[x])
                     lazy[x] += lazy[adj];

                // check if we can split
                int num_children = children[x] - lazy[x];
                if (num_children >= mid) {
                    splits++;
                    lazy[x] += num_children;
                }

            }

            if (splits > k) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        cout << low << endl;
    }
}
