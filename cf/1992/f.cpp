#include <iostream>
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
        int n, x;
        cin >> n >> x;

        vll nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        // find factors
        // 0 = can't make this product, 1 = can make this product
        map<ll, bool> possible_factors;
        for (int i = 1; i <= sqrt(x) + 1; i++) {
            if (x % i == 0) {
                possible_factors[i] = false;
                possible_factors[x / i] = false;
            }
        }

        /*for (auto p : possible_factors) {*/
        /*    cout << p.first << ">" << p.second << ", ";*/
        /*}*/
        /*cout << endl;*/
        /*cout << endl;*/
        /**/
        int ans = 0;
        for (int i = 0; i < n; i++) {

            /*cout << "checking " << nums[i] << endl;*/

            // not a factor
            if (x % nums[i] != false) {
                continue;
            }

            // adding this factor multiplies to n
            if (possible_factors[x / nums[i]]) {
                ans++;
                /*cout << "makes it bad !!! resetting..." << endl;*/
                for (auto &p : possible_factors) {
                    p.second = false;
                }
            }

            map<ll, bool> updated_factors = possible_factors;
            for (auto p : possible_factors) {
                if (p.second == false)
                    continue;
                ll new_factor = p.first * nums[i];
                if (!possible_factors.count(new_factor))
                    continue;
                updated_factors[new_factor] = true;
            }
            updated_factors[nums[i]] = true;
            possible_factors = updated_factors;

            /*for (auto p : possible_factors) {*/
            /*    cout << p.first << ">" << p.second << ", ";*/
            /*}*/
            /*cout << endl;*/
            /*cout << endl;*/
            /**/
        }

        cout << ans + 1 << endl;
    }
}
