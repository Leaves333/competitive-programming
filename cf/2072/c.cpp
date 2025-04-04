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
        int n, x;
        cin >> n >> x;

        int lowest_zero = INT_MAX;
        for (int i = 0; i < 31; i++) {
            if (!(x & 1 << i)) {
                lowest_zero = 1 << i;
                break;
            }
        }

        int nums_printed = 0;
        int total = 0;
        int last = 0;
        for (int i = 0; i < lowest_zero && nums_printed < n - 1; i++) {
            cout << i << " ";
            total |= i;
            last = i;
            nums_printed++;
        }

        if ((total | (last + 1)) == x) {
            cout << last + 1 << " ";
        } else {
            cout << x << " ";
        }
        nums_printed++;

        while (nums_printed < n) {
            cout << 0 << " ";
            nums_printed++;
        }

        cout << endl;

    }
}
