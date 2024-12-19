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
        int n, m, L;
        cin >> n >> m >> L;

        vector<pii> hurdles;
        vector<pii> powerups;
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            hurdles.push_back(make_pair(l, r));
        }
        for (int i = 0; i < m; i++) {
            int x, v;
            cin >> x >> v;
            powerups.push_back(make_pair(x, v));
        }

        priority_queue<int> pq; // stores negative powers, bc min heap
        int ans = 0;
        int cur_power = 0;
        int idx = 0;
        bool good = true;
        for (auto hurdle : hurdles) {

            /*cout << "attempting to jump " << hurdle.first << " " << hurdle.second << endl;*/
            /*cout << "curpower = " << cur_power << endl;*/

            // iterate through all the powerups she can gather before this hurdle
            while (idx < m && powerups[idx].first < hurdle.first) {
                pq.push(powerups[idx].second);
                idx++;
            }

            // eat powerups until she can jump
            while (cur_power <= hurdle.second - hurdle.first && pq.size() > 0) {
                cur_power += pq.top();
                ans++;
                /*cout << "ate a powerup, curpower is now " << cur_power << endl;*/
                pq.pop();
            }

            if (cur_power <= hurdle.second - hurdle.first) {
                good = false;
                break;
            }
        }

        cout << (good ? ans : -1) << endl;
    }
}
