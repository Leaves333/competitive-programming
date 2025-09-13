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

int sign(ll x) {
    if (x > 0) {
        return 1;
    } else if (x < 0) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vb games(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        games[i] = (s == "Notnomde");
    }

    int longest_true_streak = 0;
    int longest_false_streak = 0;
    int cur_true_streak = 0;
    int cur_false_streak = 0;

    int largest_true_lead = 0;
    int largest_false_lead = 0;
    int cur_true = 0;
    int cur_false = 0;

    for (int i = 0; i < n; i++) {
        cur_true += games[i];
        cur_false += !games[i];
        largest_true_lead = max(largest_true_lead, cur_true - cur_false);
        largest_false_lead = max(largest_false_lead, cur_false - cur_true);

        if (i == 0) {
            cur_true_streak = games[i] == true;
            cur_false_streak = games[i] == false;
        } else {
            if (games[i]) {
                cur_true_streak++;
                cur_false_streak = 0;
            } else {
                cur_false_streak++;
                cur_true_streak = 0;
            }
        }

        longest_true_streak = max(longest_true_streak, cur_true_streak);
        longest_false_streak = max(longest_false_streak, cur_false_streak);
    }

    if (sign(largest_true_lead - largest_false_lead) != sign(longest_true_streak - longest_false_streak)) {
        cout << "Disagree" << endl;
    } else {
        cout << "Agree" << endl;
    }
}
