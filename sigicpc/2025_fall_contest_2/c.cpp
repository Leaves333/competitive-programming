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

    int testcases; cin >> testcases;
    while (testcases--) {
        ll n, p, l, t;
        cin >> n >> p >> l >> t;

        ll low = 0, high = n;
        ll total_tasks = ((n - 1) / 7) + 1;
        while (low < high) {
            ll mid = low + (high - low + 1) / 2;

            ll points = mid * l;
            ll tasks = min(2 * mid, total_tasks);
            points += tasks * t;

            if (points < p) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        cout << n - low - 1 << endl;
    }
}
