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

    int n;
    cin >> n;
    vector<string> routines(n);
    vi indices(n);
    for (int i = 0; i < n; i++) {
        cin >> routines[i];
        indices[i] = i;
    }

    vvb v(n, vb(26));
    for (int i = 0; i < n; i++) {
        for (char c : routines[i]) {
            v[i][c - 'A'] = true;
        }
    }

    vvi dist(n, vi(26));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int d = 0;
            for (int k = 0; k < 26; k++) {
                if (v[i][k] && v[j][k])
                    d++;
            }
            dist[i][j] = d;
            dist[j][i] = d;
        }
    }

    int ans = INT_MAX;
    while (next_permutation(indices.begin(), indices.end())) {
        int cur = 0;
        for (int i = 0; i < n - 1; i++) {
            int x = indices[i];
            int y = indices[i+1];
            cur += dist[x][y];
        }
        ans = min(ans, cur);
    }
    cout << ans << endl;
}
