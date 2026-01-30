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

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vi arr(n);
        map<int, int> total_freq;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            total_freq[arr[i]]++;
        }

        bool good = true;
        for (auto [key, val] : total_freq) {
            if (val % k != 0) {
                good = false;
                break;
            }
        }

        if (!good) {
            cout << 0 << endl;
            continue;
        }

        map<int, int> cur_freq;
        int l = 0, r = 0;
        ll ans = 0;
        while (r < arr.size()) {
            cur_freq[arr[r]]++;
            while (cur_freq[arr[r]] > total_freq[arr[r]] / k) {
                cur_freq[arr[l]]--;
                l++;
            }
            r++;
            ans += r - l;
        }
        cout << ans << endl;
    }
}
