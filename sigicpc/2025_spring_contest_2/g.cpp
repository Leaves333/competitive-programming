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

    string s; cin >> s;
    map<char, int> ct;
    for (char c : s) {
        ct[c]++;
    }

    stack<char> stk;
    int i = 0;
    string ans = "";
    for (char c = 'a'; c <= 'z'; c++) {
        // try to put all a's, then b's, etc.
        while (ct[c] != 0) {
            while (stk.size() > 0 && stk.top() <= c) {
                ans += stk.top();
                stk.pop();
            }
            if (s[i] == c)
                ans += c;
            else
                stk.push(s[i]);
            ct[s[i]]--;
            i++;
        }
    }

    while (stk.size() > 0) {
        ans += stk.top();
        stk.pop();
    }
    cout << ans << endl;
}
