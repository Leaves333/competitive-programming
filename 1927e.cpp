#pragma GCC optimize("O3")

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
        int n, k;
        cin >> n >> k;

        // 1 13 5 10 2 12 6 9 3 11 7 8 4
        
        vi arr(n);
        int l = 1, r = n;
        for (int i = 0; i < k; i++) {
            for (int j = i; j < n; j += k) {
                if (i % 2 == 0) {
                    arr[j] = l;
                    l++;
                } else {
                    arr[j] = r;
                    r--;
                }
            }
        }

        for (int x : arr) {
            cout << x << " ";
        }
        cout << endl;
    }
}
