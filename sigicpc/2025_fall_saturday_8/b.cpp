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

    int n; cin >> n;
    int SIZE = 100;
    if (n == 2) {
        cout << -1 << endl;
        return 0;
    }
    
    string tmp = "";
    for (int i = 0; i < SIZE; i++) {
        tmp += '.';
    }
    vector<string> grid(SIZE, tmp);
    grid[0][0] = 'o';
    if (n % 2 == 0)
        grid[1][1] = 'o';
    int half = (n-1)/2;
    for (int i = 1; i <= half; i++) {
        grid[0][i] = 'o';
        grid[i][0] = 'o';
    }

    reverse(grid.begin(), grid.end());
    cout << SIZE << endl;
    for (string s : grid) {
        cout << s << endl;
    }
}
