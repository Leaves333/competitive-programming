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
        int n;
        cin >> n;
        vi nums(n);
        vb seen(n + 1, false);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            seen[nums[i]] = true;
        }

        set<int> remaining;
        for (int i = 1; i <= n; i++) {
            if (!seen[i])
                remaining.insert(i);
        }

        int l = 0, r = n - 1;
        while (l <= r && nums[l] == l + 1) {
            l++;
        }
        while (r >= l && nums[r] == r + 1) {
            r--;
        }

        if (remaining.size() == 1) {
            int val = *remaining.begin();
            if (nums[l] == 0 && val == l + 1) {
                l++;
                while (l <= r && nums[l] == l + 1) {
                    l++;
                }
            } else if (nums[r] == 0 && val == r + 1) {
                r--;
                while (r >= l && nums[r] == r + 1) {
                    r--;
                }
            }
            cout << r - l + 1 << endl;
        } else {
            cout << r - l + 1 << endl;
        }
    }
}
