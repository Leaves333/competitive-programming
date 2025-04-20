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

struct DSU {

    vi parent, size;

    void init_dsu(int n) {
        parent = vi(n);
        size = vi(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a == b)
            return;
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        DSU dsu;
        dsu.init_dsu(s.length());
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'E') {
                dsu.union_sets(i, (i + 1) % s.length());
            }
        }

        bool good = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'N') {
                if (dsu.find_set(i) == dsu.find_set((i + 1) % s.length())) {
                    good = false;
                }
            }
        }

        if (good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
