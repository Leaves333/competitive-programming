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
        vll nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        map<ll, ll> bit_freq;
        for (int x : nums) {
            for (int i = 0; i < 30; i++) {
                ll shift = 1 << i;
                if (x & shift) {
                    bit_freq[shift]++;
                }
            }
        }

        ll ans = 0;
        for (int x : nums) {
            ll cur = 0;
            for (int i = 0; i < 30; i++) {
                ll shift = 1 << i;
                if (x & shift) {
                    cur += shift * (n - bit_freq[shift]);
                } else {
                    cur += shift * bit_freq[shift];
                }
            }
            ans = max(ans, cur);
        }

        /*for (auto x : bit_freq) {*/
        /*    cout << x.first << " " << x.second << endl;*/
        /*}*/
        /*cout << endl;*/

        cout << ans << endl;

    }
}
