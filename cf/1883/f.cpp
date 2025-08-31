#include <algorithm>
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
        vi vals(n);
        for (int i = 0; i < n; i++) {
            cin >> vals[i];
        }

        vi left_indices;
        vi right_indices;

        set<int> seen;
        for (int i = 0; i < n; i++) {
            if (!seen.count(vals[i])) {
                seen.insert(vals[i]);
                left_indices.push_back(i);
            }
        }

        seen.clear();
        for (int i = n - 1; i >= 0; i--) {
            if (!seen.count(vals[i])) {
                seen.insert(vals[i]);
                right_indices.push_back(i);
            }
        }
        reverse(right_indices.begin(), right_indices.end());

        ll ans = 0;
        int idx = 0;
        for (auto x : left_indices) {
            while (right_indices[idx] < x) {
                idx++;
            }
            ans += right_indices.size() - idx;
        }

        cout << ans << endl;
    }
}
