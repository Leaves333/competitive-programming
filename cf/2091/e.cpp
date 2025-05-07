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

    int N = 1e7;
    vector<int> lp(N+1);
    vector<int> pr;

    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        ll ans = 0;
        int idx = pr.size() - 1;
        for (int i = 1; i <= n; i++) {
            int div = n / i;
            while (idx >= 0 && pr[idx] > div) {
                idx--;
            }
            ans += idx + 1;
        }
        cout << ans << endl;
    }
}
