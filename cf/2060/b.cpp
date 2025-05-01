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

        vvi cows(n, vi(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> cows[i][j];
            }
        }

        set<int> seen;
        vi mods(n);
        bool good = true;
        for (int i = 0; i < n; i++) {
            mods[cows[i][0] % n] = i;
            for (int j = 0; j < m; j++) {
                if (cows[i][j] % n != cows[i][0] % n) {
                    good = false;
                    break;
                }
            }
        }

        if (good) {
            for (auto x : mods) {
                cout << x + 1 << " ";
            }
            cout << endl;
        } else {
            cout << "-1" << endl;
        }

    }
}
