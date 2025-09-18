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

    int n; cin >> n;
    vi boys(n);
    for (int i = 0; i < n; i++) {
        cin >> boys[i];
    }
    sort(boys.begin(), boys.end());

    int m; cin >> m;
    vi girls(m);
    for (int i = 0; i < m; i++) {
        cin >> girls[i];
    }
    sort(girls.begin(), girls.end());

    int ans = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (i < n && j < m && girls[j] - boys[i] <= 1) {
            // cout << "checking: " << i << " " << j << endl;
            if (i < n && abs(boys[i] - girls[j]) <= 1) {
                // cout << "matching! " << i << " " << j << endl;
                ans++;
                i++;
            }
            j++;
        }
    }

    cout << ans << endl;

}
