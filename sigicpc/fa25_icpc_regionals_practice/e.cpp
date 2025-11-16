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

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vi knowledge(n, -1);
    int ans = 0;
    for (int i = 0; i < k; i++) {
        int j = 0;
        bool on_left = false;
        while (j < n) {
            if (knowledge[j] == -1) {
                on_left = !on_left;
            } else {
                on_left = knowledge[j];
            }
            knowledge[j] = s[j] == 'L';
            if (on_left && s[j] == 'R' || !on_left && s[j] == 'L') {
                break;
            }
            j++;
        }
        if (j == n) {
            ans++;
        }
    }

    cout << ans << endl;
}
