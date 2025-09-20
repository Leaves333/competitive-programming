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

/*
 * setting bits is always optimal in scenarios like 110000
 * will not disrupt higher bits.
 *
 * setting bits is possibly bad in 100111
 * say we want to set more bits than currently, what should these bits be?
 * claim: always set the lowest bits first
 *
 * how many operations to set the i-th bit?
 * at most 2^i?
 * two cases: setting this bit disrupts previous bits because they aren't
 * covered by any other nums, or we can set without worrying?
 *
 * want to make integers look like 2^n - 1.
 * 01
 * 11
 * does it matter?
 * 001
 * 110 = 3 ops
 *
 * 100 = 3 ops.
 * 011
 *
 * 01111
 * 01011
 *
 * why not?
 * claim: when we have 2, it doesn't matter which you add to
 * does this generalize???
 *
 * 01111
 * 01011
 * 01101
 *
 * no it does not.
 *
 * claim 2: you only ever want to increment one?
 *
 * 00011
 * 00111
 * 01111
 *
 * 00111 = 4 ops
 * 01000 = 1 op
 * 10000 = 1 op
 *
 * vs.
 * 01000 = 5 ops
 * 00111
 * 10000 = 1 op
 *
 * what???
 *
 */

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
    }
}
