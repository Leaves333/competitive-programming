#pragma optimize("O3")

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

    int t; cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        // 5 1 3
        // 0 1 2 1 2
        // 0 1 0 1 2

        // when n is even
        // 0 1 0 1 0 1
        // 0 1 2 1 0 1
        // 0 1 0 1 0 1
        
        vi nums(n);
        for (int i = 0; i < n / 2; i++) {
            nums[i*2] = 0;
            nums[(i*2)+1] = 1;
        }
        if (n % 2 == 1) {
            nums[n-1] = 2;
        }

        if (n % 2 == 1 && y-x == n-3) {
            nums[0] = 2;
            nums[y-x] = 0;
            nums[n-1] = 0;
        } else if (nums[y-x] == 0) {
            nums[y-x] = 2;
        }

        /*cout << "nums: ";*/
        /*for (auto x : nums) {*/
        /*    cout << x << " ";*/
        /*}*/
        /*cout << endl;*/
        /**/
        for (int i = 0; i < n; i++) {
            cout << nums[(n - x + i + 1) % n] << " ";
        }
        cout << endl;

    }
}
