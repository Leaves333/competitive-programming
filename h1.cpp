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

struct DSU {
    vi parent;
    vi size;

    void init_dsu(int n) {
        parent = vi(n);
        size = vi(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find_set(int v) {
        if (parent[v] == v)
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

int coords_to_idx(int a, int b, int m) { return (a * m) + b; }

pii idx_to_coords(int idx, int m) { return {idx / m, idx % m}; }

void add_comp(int comp, set<int> &seen, int &comp_size, DSU &dsu) {
    if (!seen.count(comp)) {
        seen.insert(comp);
        comp_size += dsu.size[comp];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> lines(n);
        for (int i = 0; i < n; i++) {
            cin >> lines[i];
        }

        // count num empty
        vi empty_in_row(n);
        vi empty_in_column(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (lines[i][j] == '.')
                    empty_in_row[i]++;
            }
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (lines[i][j] == '.')
                    empty_in_column[j]++;
            }
        }

        DSU dsu;
        dsu.init_dsu(n * m);
        const vector<pii> deltas = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (lines[x][y] != '#')
                    continue;
                for (pii d : deltas) {
                    int new_x = x + d.first;
                    int new_y = y + d.second;
                    if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= m)
                        continue;
                    if (lines[new_x][new_y] != '#')
                        continue;
                    dsu.union_sets(coords_to_idx(x, y, m),
                                   coords_to_idx(new_x, new_y, m));
                }
            }
        }

        // solve the problem
        int ans = 0;

        // check rows
        for (int i = 0; i < n; i++) {
            int comp_size = 0;
            set<int> seen;

            for (int j = 0; j < m; j++) {
                if (lines[i][j] != '.') {
                    add_comp(dsu.find_set(coords_to_idx(i, j, m)), seen,
                             comp_size, dsu);
                }
                if (i < n - 1 && lines[i + 1][j] != '.') {
                    add_comp(dsu.find_set(coords_to_idx(i + 1, j, m)), seen,
                             comp_size, dsu);
                }
                if (i > 0 && lines[i - 1][j] != '.') {
                    add_comp(dsu.find_set(coords_to_idx(i - 1, j, m)), seen,
                             comp_size, dsu);
                }
            }

            ans = max(ans, comp_size + empty_in_row[i]);
        }

        // check columns
        for (int j = 0; j < m; j++) {
            int comp_size = 0;
            set<int> seen;

            for (int i = 0; i < n; i++) {
                if (lines[i][j] != '.') {
                    add_comp(dsu.find_set(coords_to_idx(i, j, m)), seen,
                             comp_size, dsu);
                }
                if (j < m - 1 && lines[i][j + 1] != '.') {
                    add_comp(dsu.find_set(coords_to_idx(i, j + 1, m)), seen,
                             comp_size, dsu);
                }
                if (j > 0 && lines[i][j - 1] != '.') {
                    add_comp(dsu.find_set(coords_to_idx(i, j - 1, m)), seen,
                             comp_size, dsu);
                }
            }

            ans = max(ans, comp_size + empty_in_column[j]);
        }

        cout << ans << endl;
    }
}
