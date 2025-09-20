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
        vi ans(2 * n);

        ans[0] = n;
        ans[n] = n;
        for (int i = n - 1; i >= 1; i--) {
            ans[n - i] = i;
            ans[n + i] = i;
        }

        for (int i = 0; i < 2 * n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}
