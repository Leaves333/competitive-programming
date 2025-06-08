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

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s; cin >> s;

        map<int, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        int num_odd = 0;
        for (auto [key, val] : freq) {
            if (val % 2 == 1)
                num_odd++;
        }

        if (k < num_odd - 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}
