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

        int n; cin >> n;
        list<int> stk;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x == 1) {
                stk.push_back(x);
            } else {
                while (stk.back() != x - 1) {
                    stk.pop_back();
                }
                stk.pop_back();
                stk.push_back(x);
            }

            auto it = stk.begin();
            cout << *it;
            it++;
            while (it != stk.end()) {
                cout << "." << *it;
                it++;
            }
            cout << endl;
        }


    }
}
