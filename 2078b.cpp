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
        int n, k;
        cin >> n >> k;
        vi ans(n);
        ans[n-1] = n-1;
        ans[n-2] = n;

        int target = (k % 2 == 0) ? n-1 : n;
        for (int i = 0; i < n-2; i++) {
            ans[i] = target;
        }

        for (auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
}
