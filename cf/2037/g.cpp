#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

set<int> prime_factors(ll x) {
    set<int> res;
    for (int i = 2; i < x * x; i++) {

    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vi dp(n);
    dp[0] = 1;

    // store the sum of dp[i] for all vals with those prime factors
    map<set<int>, ll> m;

    cout << dp[n - 1] << endl;
}
