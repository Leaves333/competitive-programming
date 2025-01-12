#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

ll overlaps(ll i, ll j, ll k, ll n, ll m) {
    i += 1;
    j += 1;
    int sz = min(m, n);
    return min(min(j, m - j + 1), min(m - k + 1, k)) *
           min(min(i, n - i + 1), min(n - k + 1, k));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        ll n, m, k;
        cin >> n >> m >> k;
        /*for (int i = 0; i < n; i++) {*/
        /*    for (int j = 0; j < m; j++) {*/
        /*        cout << overlaps(i, j, k, n, m) << "\t";*/
        /*    }*/
        /*    cout << endl;*/
        /*}*/
        int w;
        cin >> w;
        vll heights(w);
        for (int i = 0; i < w; i++) {
            cin >> heights[i];
        }
        sort(all(heights), greater<ll>());

        set<pll> seen;
        priority_queue<pair<ll, pii>> pq;

        ll starting_x = n / 2;
        ll starting_y = m / 2;
        pq.push(make_pair(overlaps(starting_x, starting_y, k, n, m),
                          make_pair(starting_x, starting_y)));
        seen.insert(make_pair(starting_x, starting_y));

        ll ans = 0;
        for (int i = 0; i < w; i++) {

            ll top_overlaps = pq.top().first;
            ll x = pq.top().second.first;
            ll y = pq.top().second.second;
            ans += heights[i] * top_overlaps;

            pq.pop();

            int changes[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (auto c : changes) {
                ll new_x = x + c[0];
                ll new_y = y + c[1];
                if (new_x >= n || new_y >= m || new_x < 0 || new_y < 0) {
                    continue;
                }
                if (seen.count(make_pair(new_x, new_y))) {
                    continue;
                }
                pq.push(make_pair(overlaps(new_x, new_y, k, n, m),
                                  make_pair(new_x, new_y)));
                seen.insert(make_pair(new_x, new_y));
            }
        }

        cout << ans << endl;
    }
}
