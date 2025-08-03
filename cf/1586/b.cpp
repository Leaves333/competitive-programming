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

        vi good(n + 1, true);
        while (m--) {
            int a, b, c;
            cin >> a >> b >> c;
            good[b] = false;
        }

        int first_good = -1;
        for (int i = 1; i <= n; i++) {
            if (good[i]) {
                first_good = i;
                break;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (i != first_good) {
                cout << i << " " << first_good << endl;
            }
        }
    }
}
