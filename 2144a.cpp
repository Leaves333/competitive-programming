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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        vi psum(n + 1);
        for (int i = 0; i < n; i++) {
            psum[i + 1] = nums[i] + psum[i];
        }

        int l = 0, r = 0;
        for (int i = 1; i <= n && l == 0; i++) {
            for (int j = i + 1; j <= n - 1 && l == 0; j++) {
                int a = (psum[i]) % 3;
                int b = (psum[j] - psum[i]) % 3;
                int c = (psum[n] - psum[j]) % 3;
                if (a == b && b == c) {
                    l = i;
                    r = j;
                } else if (a != b && a != c && b != c) {
                    l = i;
                    r = j;
                }
            }
        }

        cout << l << " " << r << endl;
    }
}
