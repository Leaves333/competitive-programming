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

    string s; cin >> s;
    if (s == "first") {
        int n; cin >> n;
        vi nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        string ans = "";
        for (int x : nums) {
            while (x > 0) {
                ans += 'a' + (x % 25);
                x /= 25;
            }
            ans += "z";
        }

        cout << ans << endl;
    } else {
        string s; cin >> s;
        vi nums;

        int cur = 0;
        int pow = 1;
        for (char c : s) {
            if (c == 'z') {
                nums.push_back(cur);
                cur = 0;
                pow = 1;
            } else {
                cur += (c - 'a') * pow;
                pow *= 25;
            }
        }

        cout << nums.size() << endl;
        for (auto x : nums) {
            cout << x << " ";
        }
        cout << endl;
    }
}
