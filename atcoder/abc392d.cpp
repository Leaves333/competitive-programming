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

struct dice {
    map<int, ll> vals;
    int k;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<dice> all_dice;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        dice d;
        d.k = k;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            d.vals[x]++;
        }
        all_dice.push_back(d);
    }

    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            dice first = all_dice[i];
            dice second = all_dice[j];
            ll num = 0;
            for (const auto &[key, val] : first.vals) {
                if (second.vals.count(key))
                    num += (val * second.vals[key]);
            }
            ans = max((double) num / ((ll) first.k * second.k), ans);
        }
    }
    cout << setprecision(15) << ans << endl;

}
