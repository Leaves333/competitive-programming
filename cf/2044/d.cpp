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
        set<int> unused;
        for (int i = 1; i < n + 1; i++) {
            unused.insert(i);
        }
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            unused.erase(nums[i]);
        }

        set<int> used;
        auto it = unused.begin();
        for (int i = 0; i < n; i++) {
            if (!used.count(nums[i])) {
                cout << nums[i] << " ";
                used.insert(nums[i]);
            } else {
                cout << *it << " ";
                it++;
            }
        }
        cout << endl;
    }
}
