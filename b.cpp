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
        ll n; cin >> n;
        ll pow = 10;
        vll ans;

        while (pow < n) {
            ll mod = pow + 1;
            if (n % mod == 0) {
                ans.push_back(n / mod);
            }
            pow *= 10;
        }
        
        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;
        if (ans.size() != 0) {
            for (auto x : ans) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
}
