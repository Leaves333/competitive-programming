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
        int n; cin >> n;
        vi nums(n);
        multiset<int> sorted;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            sorted.insert(nums[i]);
        }

        vi ans;
        vi back;
        int idx = 0;
        for (auto x : nums) {
            if (x == *sorted.begin()) {
                idx++;
                ans.push_back(x);
                sorted.extract(x);
            } else {
                back.push_back(x + 1);
                sorted.extract(x);
                sorted.insert(x + 1);
            }
        }
        sort(all(back));
        ans.insert(ans.end(), all(back));
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
}
