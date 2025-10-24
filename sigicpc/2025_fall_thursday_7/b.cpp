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

bool good(const vi &nums) {
    int g = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        g = gcd(g, nums[i]);
    }
    return g == 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vi nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        int ans = INT_MAX;
        if (good(nums)) {
            ans = min(ans, 0);
        }

        for (int i = 0; i < n; i++) {
            int tmp = nums[i];
            nums[i] = gcd(nums[i], i + 1);
            if (good(nums)) {
                ans = min(ans, n - i);
            }
            nums[i] = tmp;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int tmpi = nums[i];
                int tmpj = nums[j];
                nums[i] = gcd(nums[i], i + 1);
                nums[j] = gcd(nums[j], j + 1);
                if (good(nums)) {
                    ans = min(ans, n - i + n - j);
                }
                nums[i] = tmpi;
                nums[j] = tmpj;
            }
        }

        cout << ans << endl;
    }
}
