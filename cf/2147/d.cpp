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
        map<ll, ll> freq;
        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            freq[x]++;
        }

        // take odd number with highest freq?
        priority_queue<ll> pq;
        ll a = 0, b = 0;
        for (auto &[key, val] : freq) {
            if (key % 2 == 1) {
                pq.push(val);
                ll half = (key - 1) * val / 2;
                a += half;
                b += half;
            } else {
                ll half = key * val / 2;
                a += half;
                b += half;
            }
        }

        bool turn = true;
        while (!pq.empty()) {
            if (turn)
                a += pq.top();
            else
                b += pq.top();
            pq.pop();
            turn = !turn;
        }

        cout << a << " " << b << endl;
    }
}
