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
        string s;
        cin >> s;

        int idx = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '0')
                idx = i;
        }

        int zeroes_before = 0;
        for (int i = 0; i < idx; i++) {
            if (s[i] == '0')
                zeroes_before++;
        }

        cout << s.length() - zeroes_before - 1 << endl;
    }
}
