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

    const string FAIL = "Keine Loesung";

    string s;
    cin >> s;
    if (s.length() % 2 != 0) {
        cout << FAIL << endl;
        return 0;
    }

    string ans;
    for (int i = 0; i < s.size() / 2; i++) {
        ans += '.';
    }

    stack<pair<char, int>> stk;
    for (int i = 0; i < s.length(); i += 2) {
        int idx = i / 2;
        char c = s[i];
        if (!stk.empty()) {
            char top_char = stk.top().first;
            int top_idx = stk.top().second;
            if (top_char != c) {
                stk.pop();
                ans[top_idx] = '[';
                ans[idx] = ']';
                continue;
            }
        }
        stk.push({c, idx});
    }

    if (stk.empty()) {
        cout << ans << endl;
    } else {
        cout << "Keine Loesung" << endl;
    }
}
