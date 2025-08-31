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

        sort(vals.begin(), vals.end());
        reverse(vals.begin(), vals.end());
        bool found = false;
        int idx = 0;
        for (int num_liars = n; num_liars >= 0; num_liars--) {
            while (idx < n && vals[idx] > num_liars) {
                idx++;
            }
            int actual_liars = idx;
            if (actual_liars == num_liars) {
                cout << num_liars << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << -1 << endl;
        }
    }
}
