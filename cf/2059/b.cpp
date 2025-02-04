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
        int n, k;
        cin >> n >> k;
        vll nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        if (n - k == 0) {
            int ans = 1, i = 1;
            while (i < nums.size()) {
                if (nums[i] == ans) {
                    ans++;
                    i += 2;
                } else {
                    break;
                }
            }
            cout << ans << endl;
            continue;
        }

        bool one = false;
        for (int i = 1; i < n - k + 2; i++) {
            if (nums[i] != 1) {
                one = true;
                break;
            }
        }

        if (one) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }
}
