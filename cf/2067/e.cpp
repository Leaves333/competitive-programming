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
        int nonzero = 0;
        int leftmost_zero = -1;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            if (nums[i] != 0)
                nonzero++;
            else if (leftmost_zero == -1)
                leftmost_zero = i;
        }

        if (nonzero == n) {
            cout << nonzero << endl;
            continue;
        }

        vb seen(n + 1, false);
        for (int i = leftmost_zero; i < n; i++) {
            if (nums[i] <= n)
                seen[nums[i]] = true;
        }
        int mex = 0;
        while (seen[mex]) {
            mex++;
        }

        multiset<int> s;
        for (int i = 0; i < leftmost_zero; i++) {
            s.insert(nums[i]);
        }

        bool good = true;
        for (int i = leftmost_zero - 1; i >= 0; i--) {
            int min = *s.begin();
            if (min < mex) {
                good = false;
                break;
            }
            if (nums[i] <= n)
                seen[nums[i]] = true;
            while (seen[mex]) {
                mex++;
            }
            s.erase(s.find(nums[i]));
        }

        if (good)
            cout << nonzero + 1 << endl;
        else
            cout << nonzero << endl;

    }
}
