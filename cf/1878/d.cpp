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
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vi l(k), r(k);
        for (int i = 0; i < k; i++) {
            cin >> l[i];
        }
        for (int i = 0; i < k; i++) {
            cin >> r[i];
        }

        // process each seg individually...

        vi add_reverse(n);
        vi sub_reverse(n);
        int q; cin >> q;
        while (q--) {
            int x; cin >> x;

            auto it = upper_bound(l.begin(), l.end(), x);
            int idx = it - l.begin() - 1;

            int a = min(x, r[idx] + l[idx] - x);
            int b = max(x, r[idx] + l[idx] - x);
            a--;
            b--;
            add_reverse[a]++;
            sub_reverse[b]++;
        }

        string ans = "";
        for (int i = 0; i < k; i++) {
            int reverse = 0;
            for (int j = l[i]; j <= r[i]; j++) {
                int t = j-1; // 0-based index
                reverse += add_reverse[t];

                if (reverse % 2 == 0) {
                    ans += s[t];
                } else {
                    int diff = j - l[i];
                    ans += s[r[i] - diff - 1];
                }

                reverse -= sub_reverse[t];
            }
        }

        cout << ans << endl;
    }
}
