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

        if (n == 4 && m == 4) {
            cout << "16 7 1 9\n12 8 2 3\n13 4 10 11\n14 5 6 15" << endl;
            continue;
        }

        vvi ans(n, vi(m));
        int size = n * m;

        if (n == 4) {
            int val = 0;
            for (int j = 0; j < (m+1)/2; j++) {
                for (int i = 0; i < n; i++) {
                    ans[i][j] = (val % size) + 1;
                    val++;
                }
                val += n;
            }
            val = n;
            for (int j = (m+1)/2; j < m; j++) {
                for (int i = 0; i < n; i++) {
                    ans[i][j] = (val % size) + 1;
                    val++;
                }
                val += n;
            }
        } else {
            int val = 0;
            for (int i = 0; i < (n+1) / 2; i++) {
                for (int j = 0; j < m; j++) {
                    ans[i][j] = (val % size) + 1;
                    val++;
                }
                val += m;
            }
            val = m;
            for (int i = (n+1) / 2; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ans[i][j] = (val % size) + 1;
                    val++;
                }
                val += m;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}
