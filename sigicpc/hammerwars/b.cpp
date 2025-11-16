#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<bool>> vvb;

int main() {
    int n; cin >> n;
    int a, b, c, d;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
    }
    int parity = (n + 1) / 2;
    if (parity % 2 == 1) {
        cout << "Zhongtang" << endl;
    } else {
        cout << "Arvind" << endl;
    }
}
