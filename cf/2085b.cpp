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
        vi nums(n);
        bool all_zeroes = true;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            if (nums[i] != 0)
                all_zeroes = false;
        }

        // edge case
        if (all_zeroes) {
            cout << 3 << endl;
            cout << 1 << " " << n - 2 << endl;
            cout << 2 << " " << 3 << endl;
            cout << 1 << " " << 2 << endl;
            continue;
        }

        vector<pii> operations;
        while (true) {

            /*cout << "nums is: ";*/
            /*for (auto x : nums) {*/
            /*    cout << x << " ";*/
            /*}*/
            /*cout << endl;*/
            /**/
            if (nums[0] == 0) {
                operations.push_back({1, 2});
                nums.erase(nums.begin());
                nums.erase(nums.begin());
                nums.insert(nums.begin(), 1);
                continue;
            }

            if (nums.back() == 0) {
                operations.push_back({nums.size() - 1, nums.size()});
                nums.pop_back();
                nums.pop_back();
                nums.push_back(1);
                continue;
            }

            bool found_zero = false;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    operations.push_back({i, i + 1});
                    nums.erase(nums.begin() + i - 1);
                    nums.erase(nums.begin() + i - 1);
                    nums.insert(nums.begin() + i - 1, 1);
                    found_zero = true;
                    break;
                }
            }

            if (found_zero)
                continue;

            operations.push_back({1, nums.size()});
            break;
        }

        /*cout << "nums is: ";*/
        /*for (auto x : nums) {*/
        /*    cout << x << " ";*/
        /*}*/
        /*cout << endl;*/
        /**/
        cout << operations.size() << endl;
        for (pii op : operations) {
            cout << op.first << " " << op.second << endl;
        }

    }
}
