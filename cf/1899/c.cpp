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
        vll psum(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            psum[i + 1] = psum[i] + nums[i];
        }

        ll ans = nums[0];
        multiset<ll> prev;
        prev.insert(psum[0]);
        prev.insert(psum[1]);

        int l = 0, r = 1;
        while (r < n) {
            if ((nums[r] & 1) == (nums[r-1] & 1)) {
                while (l < r) {
                    // cout << "deleting " << psum[l] << endl;
                    prev.erase(prev.find(psum[l]));
                    l++;
                }
            }

            ans = max(ans, psum[r + 1] - *prev.begin());
            // cout << "inserting " << psum[r + 1] << endl;
            prev.insert(psum[r + 1]);
            r++;
        }

        cout << ans << endl;
    }
}
