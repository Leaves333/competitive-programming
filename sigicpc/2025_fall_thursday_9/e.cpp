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

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vi nums(n);
        vi freq(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            freq[nums[i]]++;
        }
        sort(nums.begin(), nums.end());

        // mex for all is the same, or equal to cur

        for (int i = 0; i < min(k, k % 2 + 2); i++) {
            int mex = n + 1;
            for (int i = 0; i < n; i++) {
                if (freq[i] == 0) {
                    mex = i;
                    break;
                }
            }

            vi to_update;
            for (int i = 0; i < n; i++) {
                if (freq[nums[i]] == 1 && nums[i] < mex) {
                    continue;
                }
                to_update.push_back(i);
            }

            for (auto x : to_update) {
                freq[nums[x]]--;
                nums[x] = mex;
                freq[nums[x]]++;
            }
        }

        ll ans = 0;
        for (auto x : nums) {
            ans += x;
        }
        cout << ans << endl;
    }
}
