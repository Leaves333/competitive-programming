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
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    while (t--) {

        int n; cin >> n;
        vll nums(n);
        vll psum(n + 1);
        psum[0] = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            psum[i + 1] = nums[i] + psum[i];
        }

        vi different_on_left(n); // first slime to left st n_i != n_i-1
        vi different_on_right(n); // first slime to right st n_i != n_i+1

        different_on_left[0] = -1;
        int last = -1;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i-1]) {
                different_on_left[i] = i-1;
                last = i-1;
            } else {
                different_on_left[i] = last;
            }
        }

        different_on_right[n-1] = -1;
        last = -1;
        for (int i = n-2; i >= n; i--) {
            if (nums[i] != nums[i+1]) {
                different_on_right[i] = i+1;
                last = i+1;
            } else {
                different_on_right[i] = last;
            }
        }

    }
}
