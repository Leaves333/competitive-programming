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
    // only operations that matter are
    // 10 and 110 ans 100
    // 100 -> 001 vs. 100 -> 010 -> 001
    // 1010 -> 1001 -> 0011
    // 1010 -> 1001 -> 0101 -> 0011
    // shift by 2 vs shift by 1

    ll sum = 0;
    ll pos = s.length() - 1;
    for (int i = s.length(); i >= 0; i--) {
        if (s[i] == '1') {
            sum += pos - i;
            pos--;
        }
    }

    cout << (sum % 3 == 0 ? "Bob" : "Alice") << endl;

}
