#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define mp(x, y) make_pair(x, y)
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
        vi a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        int min_extra = INT_MAX;
        int missing_amount = -1;
        bool good = true;
        for (int i = 0; i < n; i++) {
            if (a[i] >= b[i]) {
                min_extra = min(min_extra, a[i]-b[i]);
            } else {
                if (missing_amount != -1) {
                    good = false;
                    break;
                }
                missing_amount = b[i]-a[i];
            }
        }

        if (good && missing_amount <= min_extra) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
