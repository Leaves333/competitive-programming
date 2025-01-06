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

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;

        // observations: there needs to be one 1 and 0 in each bit
        // choose the largest bit possible???
        // this is always achieveable??

        // scan bits from greatest to least...
        int cur_bit = -1;
        int weird_bit = -1;
        int ans = 0;
        for (int i = 30; i >= 0; i--) {
            // if min and max is both 1
            if ((l & 1 << i) & (r & 1 << i)) {
                /*cout << (1 << i) << " is set in both " << l << " and " << r << endl;*/
                ans += 1 << i;
                // if bits are different
            } else if ((l & 1 << i) ^ (r & 1 << i)) {
                weird_bit = i;
                cur_bit = i - 1;
                break;
            }
        }

        /*cout << "base: " << ans << endl;*/

        while (cur_bit >= 0) {
            if (!((l & 1 << cur_bit) | (r & 1 << cur_bit))) {
                ans += 1 << cur_bit;
            }
            cur_bit--;
        }

        if (ans < l) {
            ans += 1 << weird_bit;
        }
        if (ans == r) {
            ans--;
        }
        if (ans == l) {
            ans++;
        }

        cout << l << " " << r << " " << ans << endl;
        /*cout << endl;*/
    }
}
