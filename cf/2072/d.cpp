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
        vi nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        vi ct(n), pos(n);
        for (int i = 0; i < n; i++) {
            pos[i] = i;
            int inversions = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] < nums[i])
                    inversions++;
                if (nums[j] > nums[i])
                    inversions--;
                if (inversions > ct[i]) {
                    ct[i] = inversions;
                    pos[i] = j;
                }
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (ct[i] > ct[ans])
                ans = i;
        }
        cout << ans + 1 << " " << pos[ans] + 1 << endl;

    }
}
