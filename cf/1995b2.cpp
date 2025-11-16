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
        ll n, m;
        cin >> n >> m;
        vll prices(n), amounts(n);
        for (int i = 0; i < n; i++) {
            cin >> prices[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> amounts[i];
        }

        map<ll, ll> flowers;
        for (int i = 0; i < n; i++) {
            flowers[prices[i]] = amounts[i];
        }

        ll ans = 0;

        // check pairs
        auto it_first = flowers.begin(), it_second = flowers.begin();
        it_second++;
        while (it_second != flowers.end()) {
            if (it_second->first != it_first->first + 1) {
                // petal costs aren't adjacent...
                ll petals = prices[0] * max(m / prices[0], amounts[0]);
                ans = max(ans, petals);
            } else {
                
            }
            it_first++;
            it_second++;
        }

        // check also just the first
        ll petals = prices[0] * max(m / prices[0], amounts[0]);
        ans = max(ans, petals);
        cout << ans << endl;

    }
}
