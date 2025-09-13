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

    const int N = 10000 + 10;
    vll cards(N);

    int n;
    cin >> n;
    int total_cards = n;
    int x;
    while (n--) {
        cin >> x;
        cards[x]++;
    }

    int ans = 0;
    while (total_cards > 0) {

        // find longest streak
        int l = -1, r = -1;
        int start = -1;
        for (int i = 0; i < N; i++) {
            if (cards[i] > 0 && start == -1) {
                start = i;
            } else if (cards[i] <= 0) {
                if (start != -1) {
                    int len = i - start;
                    if (i - start > r - l) {
                        r = i;
                        l = start;
                    }
                    start = -1;
                }
            }
        }

        // remove cards
        for (int i = l; i < r; i++) {
            cards[i]--;
        }

        ans++;
        total_cards -= r - l;
    }

    cout << ans << endl;
}
