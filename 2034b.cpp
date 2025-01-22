#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;

        int ans = 0;
        int combo = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                combo++;
            } else {
                combo = 0;
            }
            if (combo >= m) {
                ans++;
                combo = 0;
                /*cout << i << "!" << endl;*/
                i += k - 1;
            }
        }
        cout << ans << endl;
    }
}
