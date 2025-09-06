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

const ll CUT = 556;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m, l;
    cin >> n >> m >> l;
    
    vll folds(n);
    for (int i = 0; i < n; i++) {
        cin >> folds[i];
    }
    folds.push_back(0);

    vector<pll> points;
    for (int i = 0; i < m; i++) {
        ll x; cin >> x;
        points.push_back({x, CUT});
    }
    points.push_back({LLONG_MAX, CUT});

    bool pos_dir = true;
    ll last_pos = 0, last_dist = l;
    for (int i = 0; i <= n; i++) {
        ll new_pos = last_pos + (pos_dir ? 1 : -1) * (last_dist - folds[i]);
        pos_dir ^= true;

        points.push_back({min(last_pos, new_pos), 1});
        points.push_back({max(last_pos, new_pos), -1});

        last_pos = new_pos;
        last_dist = folds[i];
    }

    sort(points.begin(), points.end());
    ll ans = 0, layers = 0;
    last_pos = LLONG_MIN;

    for (auto [pos, op] : points) {
        ans += (pos - last_pos) * layers;
        if (op == CUT) {
            cout << ans << " ";
            ans = 0;
        } else if (op == 1) {
            layers++;
        } else {
            layers--;
        }
        last_pos = pos;
    }

    cout << endl;
}

