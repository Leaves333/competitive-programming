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

    int n;
    cin >> n;
    vi nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int l = 0, r = n - 1;
    ll a = 0, b = 0;
    int turn = 1;
    while (l <= r) {
        if (nums[l] < nums[r]) {
            if (turn % 2)
                a += nums[r];
            else
                b += nums[r];
            r--;
        } else {
            if (turn % 2)
                a += nums[l];
            else
                b += nums[l];
            l++;
        }
        turn++;
    }

    cout << a << " " << b << endl;
}
