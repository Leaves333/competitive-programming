#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
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
        int n, m;
        cin >> n >> m;

        int kevin_rating = 0;
        vi participants(n - 1);
        vi problems(n);

        cin >> kevin_rating;
        for (int i = 0; i < n - 1; i++) {
            cin >> participants[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> problems[i];
        }
        sort(all(problems));
        sort(all(participants));

        int problem_diff = 0; // easiest problem that kevin couldn't solve
        int l = 0, h = n;
        while (l < h) {
            int mid = l + (h - l + 1) / 2;
            if (problems[mid] <= kevin_rating) {
                l = mid;
            } else {
                h = mid - 1;
            }
        }

        problem_diff = problems[l + 1];
        cout << "initial problem diff=" << problem_diff << endl;

        for (int k = 1; k <= m; k++) {
            int problem_diff = problems[l + 1];
            int problem_idx = k - 1;
            int ans = 0;
            cout << "checking for k=" << k << endl;
            while (problem_idx < m) {
                cout << "problem idx: " << problem_idx << endl;
                if (problems[problem_idx] <= kevin_rating) {
                    ans++;
                } else {

                    problem_diff = max(problem_diff, problems[problem_idx - k]);
                    cout << "problem diff is now " << problem_diff << endl;

                    int low = 0, high = n - 2;
                    while (low < high) {
                        int mid = low + (high - low + 1) / 2;
                        cout << "searching... " << low << " " << mid << " " << high << endl;
                        if (participants[mid] < problem_diff) {
                            low = mid;
                        } else {
                            high = mid - 1;
                        }
                    }
                    cout << low + 1 << " participants couldn't solve" << endl;
                    cout << n - 2 - low << " is kevin's rank" << endl << endl;
                    ans += n - 2 - low;
                }
                problem_idx += k;
            }
            cout << "k=" << k << "\t";
            cout << ans << " " << endl;
        }
        cout << endl;
        cout << endl;

    }
}
