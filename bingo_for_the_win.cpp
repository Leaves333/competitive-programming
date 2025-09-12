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

    int n, k;
    cin >> n >> k;
    map<ll, ll> last_seen;
    vll last_count(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            if (last_seen.count(x)) {
                last_count[last_seen[x]]--;
                last_count[i]++;
            } else {
                last_count[i]++;
            }
            last_seen[x] = i;
        }
    }

    ll total = 0;
    for (int i = 0; i < n; i++) {
        total += last_count[i];
    }

    cout << setprecision(20) << endl;
    for (int i = 0; i < n; i++) {
        double ans = (double) last_count[i] / (double) total;
        cout << ans << endl;
    }

}
