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
        int n; cin >> n;
        vll nums(n);
        bool has_odd = false, has_even = false;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            if (nums[i] % 2 == 0) {
                has_even = true;
            } else {
                has_odd = true;
            }
        }

        if (has_odd && has_even) {
            sort(nums.begin(), nums.end());
        }
        for (int x : nums) {
            cout << x << " ";
        }
        cout << endl;
    }
}
