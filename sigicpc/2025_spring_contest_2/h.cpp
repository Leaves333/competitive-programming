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

    int n; cin >> n;
    string s; cin >> s;

    set<char> total_chars;
    for (char c : s) {
        total_chars.insert(c);
    }
    int target = total_chars.size();

    map<char, int> ct;
    int best_size = INT_MAX;
    int l = 0;
    for (int r = 0; r < n; r++) {
        ct[s[r]]++;
        while (ct.size() == target) {
            best_size = min(best_size, r - l);
            ct[s[l]]--;
            if (ct[s[l]] <= 0)
                ct.erase(ct.find(s[l]));
            l++;
        }
    }

    cout << best_size + 1 << endl;
}
