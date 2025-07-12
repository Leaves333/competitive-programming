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
        int n; cin >> n;
        vll nums(n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            sum += nums[i];
        }

        int diff = nums[0] - nums[1];
        bool good = true;
        for (int i = 1; i < n-1; i++) {
            if (diff != nums[i] - nums[i+1]) {
                good = false;
            }
        }

        if (!good) {
            cout << "NO" << endl;
            continue;
        }
        
        ll target = 0;
        if (diff > 0)
            target = nums.back() - diff;
        else
            target = nums.front() + diff;
        for (int i = 0; i < n; i++) {
            nums[i] = target;
        }

        if (target < 0 || target % (n + 1) != 0) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

    }
}
