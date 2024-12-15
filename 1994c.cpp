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
        int n, x;
        cin >> n >> x;
        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        ll ans = 0;
        for (int l = 0; l < n; l++) {
            int val = 0;
            for (int r = l; r < n; r++) {
                val += arr[r];
                if (val > x) { val = 0; }
                if (val != 0) { ans++; }
            }
        }

        cout << ans << endl;
    }
}
