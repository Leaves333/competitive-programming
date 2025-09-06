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

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> lines(n);

        for (int i = 0; i < n; i++) {
            cin >> lines[i];
        }

        int x = -1, y = -1;
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            int len = 0;
            for (int j = 0; j < m; j++) {
                if (lines[i][j] == '#') {
                    len++;
                    if (y == -1)
                        y = j;
                }
            }
            if (len > max_len) {
                x = i;
                max_len = len;
            }
        }

        cout << x + 1 << " " << y + 1 << endl;
    }
}
