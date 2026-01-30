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

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        int ans = 0;
        int time = 0, side = 0;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;

            if (b == side) {
                ans += ((a - time) / 2) * 2;
            } else {
                time++;
                ans++;
                ans += ((a - time) / 2) * 2;
            }
            time = a;
            side = b;
        }

        ans += m - time;
        cout << ans << endl;
    }
}
