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

map<int, int> factorize(int x) {
    int i = 2;
    map<int, int> res;
    while (x > 1) {
        while (x % i == 0) {
            res[i]++;
            x /= i;
        }
        i++;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int l, w, n;
    cin >> l >> w >> n;
    vector<string> grid;
    if ((l * w) % n != 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    map<int, int> l_factors = factorize(l);
    int length = 1, width = (l * w) / n;
    for (auto &[key, val] : l_factors) {
        while (width % key == 0 && val > 0) {
            val--;
            length *= key;
            width /= key;
        } 
    }

    for (int i = 0; i < l; i++) {
        string s = "";
        for (int j = 0; j < w; j++) {
            int offset = (i / length) * (w / width) + (j / width);
            s += ('A' + offset);
        }
        grid.push_back(s);
    }

    for (string s : grid) {
        cout << s << endl;
    }
}
