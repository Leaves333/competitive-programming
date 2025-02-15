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

    int n, m;
    cin >> n >> m;
    set<int> vals;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        vals.insert(x);
    }
    
    vector<int> missing;
    for (int i = 1; i <= n; i++) {
        if (!vals.count(i)) {
            missing.push_back(i);
        }
    }

    cout << missing.size() << endl;
    for (int x : missing) {
        cout << x << " ";
    }
    cout << endl;
}
