#include <set>
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
        int n, k;
        cin >> n >> k;
        vll nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        map<int, int> m;
        int skips = n - k;
        for (int i = 1; i < skips + 1; i++) {
            cout << "adding " << i << endl;
            m[nums[i]]++;
        }

        int ans = 1;
        for (int i = 1; i < n-skips; i += 2) {
            // consider elements from 1 to 1+skips, can we choose something that is not 1...
            // if not, consider elements from 2 to 2+skips, can we choose something that is not 2...
            // if not, etc

            cout << "adding " << skips + i << endl;
            m[nums[skips + i]]++;

            cout << "checking... " << endl;
            for (auto x : m) {
                cout << x.first << " -> " << x.second << endl;
            }

            if (m[(i+1)/2] <= skips) {
                break;
            }
            ans++;

            cout << "deleting " << i << endl;
            m[nums[i]]--;

            if (skips + i + 1 < n) {
                cout << "adding " << skips + i + 1 << endl;
                m[nums[skips + i + 1]]++;
            }

            if (i + 1 < n) {
                cout << "deleting " << i + 1 << endl;
                m[nums[i+1]]--;
            }

        }

        cout << ans << endl;
        cout << endl;
    }
}
