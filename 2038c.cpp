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
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            m[x]++;
        }

        auto it = m.begin();
        vi nums;
        while (it != m.end()) {
            while (it->second >= 2) {
                it->second -= 2;
                nums.push_back(it->first);
            }
            it++;
        }

        if (nums.size() < 4) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << nums[0] << " " << nums[1] << " " << nums[0] << " " << nums[nums.size()-1] << " ";
            cout << nums[nums.size()-2] << " " << nums[1] << " " << nums[nums.size()-2] << " " << nums[nums.size()-1] << endl;
        }
    }
}
