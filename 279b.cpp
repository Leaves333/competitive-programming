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

    int n, t;
    cin >> n >> t;
    vi nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vll psum(n+1);
    psum[0] = 0;
    for (int i = 0; i < n; i++) {
        psum[i + 1] = psum[i] + nums[i];
    }

    int ans = 0;
    int l = 0, r = 0;
    while (r < n) {
        ans = max(ans, r-l);
    }

    cout << ans << endl;
}
