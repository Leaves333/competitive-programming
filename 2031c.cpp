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
        int n; cin >> n;
        if (n % 2 == 1 && n <= 26) {
            cout << -1 << endl;
            continue;
        }

        vi ans(n);
        int k = 1;
        ans[0] = 1;
        if (n % 2 == 1) {
            ans[9] = 1;
            ans[25] = 1;
            ans[22] = 2;
            ans[26] = 2;
            k = 3;
        }

        for (int i = 1; i < n; i++) {
            if (ans[i] != 0) {
                continue;
            }
            ans[i] = k;
            if (ans[i - 1] == k) {
                k++;
            }
        }

        for (auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
}
