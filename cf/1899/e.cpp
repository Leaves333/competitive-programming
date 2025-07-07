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
        int min_idx = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            if (nums[i] < nums[min_idx])
                min_idx = i;
        }

        bool good = true;
        for (int j = min_idx + 1; j < n; j++) {
            if (nums[j] < nums[j-1]) {
                good = false;
                break;
            }
        }

        if (good) {
            cout << min_idx << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
