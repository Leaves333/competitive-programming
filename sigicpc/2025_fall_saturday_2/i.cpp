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

bool sign(ll x) {
    if (x < 0)
        return false;
    else
        return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll a, b, c;
    cin >> a >> b >> c;

    ll first = b - a, second = c - b;
    if (sign(first) != sign(second)) {
        cout << "turned" << endl;
    } else if (abs(second) > abs(first)) {
        cout << "accelerated" << endl;
    } else if (abs(second) < abs(first)) {
        cout << "braked" << endl;
    } else {
        cout << "cruised" << endl;
    }
}
