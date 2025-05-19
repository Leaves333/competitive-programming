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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int nums_greater = 0;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) {
                    nums_greater++;
                }
            }
            ans = min(ans, nums_greater + i);
        }
        cout << ans << endl;
    }
}
