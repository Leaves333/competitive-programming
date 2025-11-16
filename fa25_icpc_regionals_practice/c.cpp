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

    string s;
    cin >> s;
    vi freq(26);
    for (char c : s) {
        freq[c - 'a']++;
    }

    int one = 0, two = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] >= one) {
            two = one;
            one = freq[i];
        }
    }

    cout << s.length() - one - two << endl;
}
