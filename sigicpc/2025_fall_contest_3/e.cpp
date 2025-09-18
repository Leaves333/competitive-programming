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

void add(int x, const vvi &divisors, map<ll, ll> &freq, int &total_occurences,
         int m) {
    for (auto v : divisors[x]) {
        if (v > m)
            continue;
        if (freq[v] == 0)
            total_occurences++;
        freq[v]++;
    }
}

void remove(int x, const vvi &divisors, map<ll, ll> &freq,
            int &total_occurences, int m) {
    for (auto v : divisors[x]) {
        if (v > m)
            continue;
        if (freq[v] == 1)
            total_occurences--;
        freq[v]--;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    const ll N = 100001;
    vvi divisors(N + 1);
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                divisors[i].push_back(j);
                divisors[i].push_back(i / j);
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vll nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());

        int total_accounted = 0;
        ll ans = LLONG_MAX;
        ll l = 0, r = 0;
        map<ll, ll> freq;
        while (r < n) {
            add(nums[r], divisors, freq, total_accounted, m);
            r++;
            while (l < n && total_accounted >= m) {
                remove(nums[l], divisors, freq, total_accounted, m);
                l++;
            }
            if (l > 0) {
                ans = min(ans, nums[r - 1] - nums[l - 1]);
            }
        }
        cout << ((ans == LLONG_MAX) ? -1 : ans) << endl;
    }
}
