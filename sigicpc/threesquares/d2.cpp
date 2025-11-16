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

    const ll limit = pow(2, 32);

    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vll nums(n);
        ll big = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            big = max(big, nums[i]);
        }

    }
}
