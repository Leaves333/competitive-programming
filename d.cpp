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
        string a, b;
        cin >> a >> b;

        // char, len
        vector<pii> hit_sequences;
        vector<pii> sound_sequences;

        char last = a[0];
        int len = 1;
        for (int i = 1; i < a.length(); i++) {
            if (a[i] != a[i-1]) {
                hit_sequences.push_back({last, len});
                last = a[i];
                len = 1;
            } else {
                len++;
            }
        }
        hit_sequences.push_back({last, len});

        last = b[0];
        len = 1;
        for (int i = 1; i < b.length(); i++) {
            if (b[i] != b[i-1]) {
                sound_sequences.push_back({last, len});
                last = b[i];
                len = 1;
            } else {
                len++;
            }
        }
        sound_sequences.push_back({last, len});

        /*cout << "hit se:" << endl;*/
        /*for (auto p : hit_sequences) {*/
        /*    cout << (char) p.first << " " << p.second << endl;*/
        /*}*/
        /*cout << "sound se:" << endl;*/
        /*for (auto p : sound_sequences) {*/
        /*    cout << (char) p.first << " " << p.second << endl;*/
        /*}*/
        /**/
        if (hit_sequences.size() != sound_sequences.size()) {
            cout << "NO" << endl;
            continue;
        }

        bool good = true;
        for (int i = 0; i < hit_sequences.size(); i++) {
            pii hit = hit_sequences[i];
            pii sound = sound_sequences[i];

            if (hit.first != sound.first) {
                good = false;
                break;
            }
            if (sound.second < hit.second) {
                good = false;
                break;
            }
            if (hit.second * 2 < sound.second) {
                good = false;
                break;
            }
        }

        if (good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
}
