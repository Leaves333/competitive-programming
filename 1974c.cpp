#pragma GCC optimize("O3")

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

        int n;
        cin >> n;
        vi nums(3);
        cin >> nums[0] >> nums[1];

        map<pii, ll> different_first;
        map<pii, ll> different_middle;
        map<pii, ll> different_last;
        map<pair<pii, int>, ll> triplets_count;
        ll ans = 0;

        for (int i = 0; i < n - 2; i++) {

            cin >> nums[2];
            int val = different_first[make_pair(nums[1], nums[2])];
            int existing =
                triplets_count[make_pair(make_pair(nums[0], nums[1]), nums[2])];
            ans += val - existing;

            val = different_middle[make_pair(nums[0], nums[2])];
            ans += val - existing;

            val = different_last[make_pair(nums[0], nums[1])];
            ans += val - existing;

            different_first[make_pair(nums[1], nums[2])]++;
            different_middle[make_pair(nums[0], nums[2])]++;
            different_last[make_pair(nums[0], nums[1])]++;
            triplets_count[make_pair(make_pair(nums[0], nums[1]), nums[2])]++;

            nums[0] = nums[1];
            nums[1] = nums[2];
        }

        cout << ans << endl;
    }
}
