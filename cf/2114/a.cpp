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

    map<int, int> squares;
    for (int i = 0; i <= 100; i++) {
        squares[i * i] = i;
    }

    int t; cin >> t;
    while (t--) {
        string n;
        cin >> n;
        int val = stoi(n);
        if (!squares.count(val))
            cout << -1 << endl;
        else
            cout << 0 << " " << squares[val] << endl;
    }
}
