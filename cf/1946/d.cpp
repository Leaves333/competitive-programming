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

        int n, x;
        cin >> n >> x;

        vll nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        x++; // check for if less than x
        int ans = -1;
        for (int shift = 30; shift >= 0; shift--) {

            // brute force trying to compress subsegments
            int mask = 1 << shift;
            vll compressed_nums;
            int count = 0;
            for (auto num : nums) {
                if (count % 2 == 0)
                    compressed_nums.push_back(num);
                else
                    compressed_nums.back() ^= num;
                if (num & mask)
                    count++;
            }

            if (!(x & mask)) {
                if (count % 2 == 1)
                    break;
                nums = compressed_nums;
            } else {
                if (count % 2 == 0)
                    ans = max(ans, (int) compressed_nums.size());
            }

        }

        cout << ans << endl;

    }
}
