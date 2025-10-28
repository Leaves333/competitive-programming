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

    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        string a, b;
        cin >> a >> b;
        vector<int> freqa(26, 0);
        vector<int> freqb(26, 0);
        for (char x : a) {
            freqa[x - 'a']++;
        }
        for (char x : b) {
            freqb[x - 'a']++;
        }

        bool good = true;
        for (int i = 0; i < 26; i++) {
            if (freqa[i] != freqb[i]) {
                good = false;
                break;
            }
        }

        if (good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
