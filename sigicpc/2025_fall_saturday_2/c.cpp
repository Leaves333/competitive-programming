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

    int length, height, k;
    cin >> length >> height >> k;

    string blank = "";
    for (int i = 0; i < length; i++) {
        blank += "_";
    }
    vector<string> lid(height, blank);

    for (int i = 0; i < k; i++) {
        int l, h, a, b;
        cin >> l >> h >> a >> b;

        for (int y = b; y < b + h && y < height; y++) {
            for (int x = a; x < a + l && x < length; x++) {
                lid[y][x] = 'a' + i;
            }
        }
    }

    for (string s : lid) {
        cout << s << endl;
    }
}
