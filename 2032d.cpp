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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi parent(n, -1);
        parent[1] = 0;

        // find out how many different paths there are
        vi current_layer;
        current_layer.push_back(1);
        int next_node = 1;
        while (true) {
            next_node++;
            cout << "? " << 1 << " " << next_node << endl;
            int response;
            cin >> response;
            if (response == 0) {
                break;
            }
            parent[next_node] = 0;
            current_layer.push_back(next_node);
        }

        int rem_nodes_idx = 1;
        vi next_layer;
        next_layer.push_back(next_node);
        parent[next_node] = 1;
        next_node++;

        if (rem_nodes_idx >= current_layer.size()) {
            current_layer = next_layer;
            next_layer.clear();
            rem_nodes_idx = 0;
        }

        while (next_node < n) {

            cout << "? " << current_layer[rem_nodes_idx] << " " << next_node << endl;
            int response;
            cin >> response;
            if (response == 0) { // on the same path
                parent[next_node] = current_layer[rem_nodes_idx];
                next_layer.push_back(next_node);
                next_node++;
            }
            rem_nodes_idx++;
            if (rem_nodes_idx >= current_layer.size()) {
                current_layer = next_layer;
                next_layer.clear();
                rem_nodes_idx = 0;
            }
        }

        cout << "! ";
        for (int i = 1; i < n; i++) {
            cout << parent[i] << " ";
        }
        cout << endl;
    }
}
