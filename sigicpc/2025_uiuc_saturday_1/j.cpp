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

    ll n, l, p;
    cin >> n >> l >> p;
    vll nums(p);
    for (int i = 0; i < p; i++) {
        cin >> nums[i];
    }

    vll amt(n);
    ll max_dist = 0;

    for (ll x : nums) {
        ll car = x / l;
        if (car >= n)
            car = n - 1;
        amt[car]++;
        ll dist = abs((car * l + (l / 2)) - x);
        max_dist = max(max_dist, dist);
    }

    ll big = 0;
    for (int i = 0; i < amt.size(); i++) {
        big = max(big, amt[i]);
    }
    cout << max_dist << "\n" << big << endl;
}
