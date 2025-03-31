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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vi center(n);
        vi radius(n);
        for (int i = 0; i < n; i++) {
            cin >> center[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> radius[i];
        }

        map<int, int> heights;
        for (int i = 0; i < n; i++) {
            int h = radius[i];
            int r = radius[i];
            for (int x = 0; x <= radius[i]; x++) {
                while ((x * x) + (h * h) > r * r) {
                    h--;
                }
                heights[center[i] + x] = max(heights[center[i] + x], h);
                heights[center[i] - x] = max(heights[center[i] - x], h);
            }
        }

        ll ans = 0;
        for (auto const &[pos, height] : heights) {
            ans += (height * 2) + 1;
        }
        cout << ans << endl;
    }
}
