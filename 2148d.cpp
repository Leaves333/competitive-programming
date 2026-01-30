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
        ll even_sum = 0;
        vll odd_nums;
        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            if (x % 2 == 0) {
                even_sum += x;
            } else {
                odd_nums.push_back(x);
            }
        }
        
        ll ans = 0;
        sort(odd_nums.begin(), odd_nums.end());
        reverse(odd_nums.begin(), odd_nums.end());
        if (odd_nums.size() > 0) {
            ans += even_sum;
        }

        for (int i = 0; i < (odd_nums.size() + 1) / 2; i++) {
            ans += odd_nums[i];
        }
        cout << ans << endl;
    }
}
