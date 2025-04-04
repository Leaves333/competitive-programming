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

    /*string rows[4] = {"1000", "1100", "1010", "1111"};*/

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vi ans;
        ans.push_back(k);
        switch (n % 4) {
            case 0:
                n -= 4;
                ans.push_back(k);
                ans.push_back(k);
                ans.push_back(k);
                break;
            case 1:
                ans.push_back(0);
                ans.push_back(0);
                ans.push_back(0);
                break;
            case 2:
                ans.push_back(k);
                ans.push_back(0);
                ans.push_back(0);
                break;
            case 3:
                ans.push_back(0);
                ans.push_back(k);
                ans.push_back(0);
                break;
        } 
        n /= 4;

        while (n > 0) {
            int m = n % 4;
            n /= 4;
            int sz = ans.size();

            if (m == 0) {
                // 1 0 0 0
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < sz; j++) {
                        ans.push_back(0);
                    }
                }
            } else if (m == 1) {
                // 1 1 0 0
                for (int j = 0; j < sz; j++) {
                    ans.push_back(ans[j]);
                }
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < sz; j++) {
                        ans.push_back(0);
                    }
                }
            } else if (m == 2) {
                // 1 0 1 0
                for (int j = 0; j < sz; j++) {
                    ans.push_back(0);
                }
                for (int j = 0; j < sz; j++) {
                    ans.push_back(ans[j]);
                }
                for (int j = 0; j < sz; j++) {
                    ans.push_back(0);
                }
            } else {
                // 1 1 1 1
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < sz; j++) {
                        ans.push_back(ans[j]);
                    }
                }
            }

        }

        while (ans.back() == 0)
            ans.pop_back();
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }
}
