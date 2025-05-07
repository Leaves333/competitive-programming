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
        int n; cin >> n;
        map<int, int> ct;
        int ans = 0;
        bool found = false;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            ct[x]++;
            if (ct[0] >= 3 && ct[1] >= 1 && ct[2] >= 2 && ct[3] >= 1 && ct[5] >= 1) {
                if (!found)
                    ans = i + 1;
                found = true;
            }
        }
        cout << ans << endl;
    }
}
