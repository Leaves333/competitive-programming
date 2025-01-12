#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    while (t--) {
        int n, k, l;
        cin >> n >> k >> l;
        vi scarecrows(n);
        for (int i = 0; i < n; i++) {
            cin >> scarecrows[i];
            scarecrows[i] *= 2;
        }
        k *= 2;
        l *= 2;

        int time = 0, pos = 0, idx = 1;
        time = scarecrows[0];
        pos = k;

        while (pos < l && idx < n) {

            // next scarecrow can already be positioned at pos
            if (abs(scarecrows[idx]-pos) <= time) {
                pos += k;
                idx++;
                continue;
            }

            // next scarecrow is behind pos
            if (scarecrows[idx] + time <= pos) {
                pos = max(pos, scarecrows[idx] + time + k);
                idx++;
                continue;
            }

            // need to move next scarecrow
            int distance = scarecrows[idx] - time - pos;
            int time_to_move = distance / 2;
            if (pos + time_to_move >= l) {
                break;
            }

            pos += time_to_move;
            pos += k;
            time += time_to_move;
            idx++;

        }
        
        if (pos < l) {
            time += l - pos;
        }

        cout << time << endl;
    }
}
