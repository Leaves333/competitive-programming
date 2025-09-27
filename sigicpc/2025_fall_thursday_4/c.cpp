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
        ll n, k;
        cin >> n >> k;
        vector<pll> balls;
        for (int i = 0; i < n; i++) {
            ll x, y;
            cin >> x >> y;
            balls.push_back({x, y});
        }

        bool good = false;
        for (int i = 0; i < n; i++) {
            int ct = 0;
            for (int j = 0; j < n; j++) {
                if (abs(balls[i].first - balls[j].first) + abs(balls[i].second - balls[j].second) <= k) {
                    ct++;
                }
            }
            if (ct == n) {
                good = true;
                break;
            }
        }

        cout << (good ? 1 : -1) << endl;
    }
}
