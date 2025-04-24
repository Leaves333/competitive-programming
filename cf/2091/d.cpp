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
        ll n, m, k;
        cin >> n >> m >> k;

        int low = 0, high = m;
        while (low < high) {
            ll mid = low + (high - low) / 2;
            ll groups = m / (mid + 1);
            ll seats = (mid * groups) + (m % (mid + 1));
            seats *= n;
            if (seats >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        cout << low << endl;
    }
}
