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

    int n, m;
    cin >> n >> m;
    vll nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vll dp_left(n);
    vll dp_right(n);
    for (int i = 1; i < n; i++) {
        dp_left[i] = dp_left[i - 1] + max(0ll, nums[i - 1] - nums[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        dp_right[i] = dp_right[i + 1] + max(0ll, nums[i + 1] - nums[i]);
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l < r) {
            cout << dp_left[r] - dp_left[l] << endl;
        } else {
            cout << dp_right[r] - dp_right[l] << endl;
        }
    }
}
