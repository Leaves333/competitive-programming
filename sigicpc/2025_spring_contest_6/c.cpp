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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;

        vi nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        vi can_sort;
        vector<bool> added(n, false);
        for (int i = 0; i < n - x; i++) {
            if (!added[i]) {
                can_sort.push_back(nums[i]);
                added[i] = true;
            }
            if (!added[i + x]) {
                can_sort.push_back(nums[i + x]);
                added[i + x] = true;
            }
        }

        sort(can_sort.begin(), can_sort.end());
        for (int i = 0; i < (can_sort.size() + 1) / 2; i++) {
            nums[i] = can_sort[i];
            nums[n - i - 1] = can_sort[can_sort.size() - i - 1];
        }

        bool good = true;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                good = false;
                break;
            }
        }

        if (good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
}
