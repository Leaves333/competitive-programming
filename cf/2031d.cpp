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

        multiset<int> right_side;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            right_side.insert(nums[i]);
        }

        int ct = 0;
        int left_max = INT_MIN;
        for (int i = 0; i < n; i++) {
            ct++;
            left_max = max(left_max, nums[i]);
            right_side.erase(right_side.find(nums[i]));
            if (left_max <= *right_side.begin()) {
                for (int j = 0; j < ct; j++) {
                    cout << left_max << " ";
                }
                ct = 0;
            }
        }

        for (int j = 0; j < ct; j++) {
            cout << left_max << " ";
        }
        cout << endl;
        
    }
}
