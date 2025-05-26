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
        string s;
        cin >> s;
        int zeroes = 0, ones = 0;
        for (char c : s) {
            if (c == '0')
                zeroes++;
            else
                ones++;
        }

        int bad_pairs = (n / 2) - k;
        if (bad_pairs > zeroes || bad_pairs > ones) {
            cout << "NO" << endl;
            continue;
        }

        ones -= bad_pairs;
        zeroes -= bad_pairs;
        if (ones % 2 == 0 && zeroes % 2 == 0) {
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
    }
}
