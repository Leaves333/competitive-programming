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
        string s;
        cin >> s;
        vi indices;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                indices.push_back(i + 1);
            }
        }

        if (indices.size() == n) {
            cout << 0 << endl << endl;
        } else {
            cout << indices.size() << endl;
            for (auto x : indices) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
}
