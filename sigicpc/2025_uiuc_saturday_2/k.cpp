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

double calculate_time(const vector<pii> &wormholes, const double speed) {
    double time_taken = 0;
    double v_initial = speed;

    for (auto &wormhole : wormholes) {
        double dist = wormhole.first;
        double accel = wormhole.second;

        // if accel is negative, check if we'll be able to make it
        if (accel < 0) {
            double time = v_initial / abs(accel);
            double max_dist = (v_initial * time) + (0.5 * accel * time * time);
            if (max_dist < dist)
                return -1;
        }

        // calculate speed at the end of the tunnel
        double v_final = (v_initial * v_initial) + (2 * accel * dist);
        v_final = sqrt(v_final);

        // calculate time taken
        time_taken += (2 * dist) / (v_initial + v_final);

        // set our initial speed for the next wormhole
        v_initial = v_final;
    }

    return time_taken;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<pii> wormholes(n);
    for (int i = 0; i < n; i++) {
        int d, a;
        cin >> d >> a;
        wormholes[i] = {d, a};
    }

    double low = 0.0, high = 1e9;
    int iterations = 200;
    while (iterations--) {
        double mid = (low + high) / 2;
        // cout << "running... " << low << " " << high << endl;
        if (calculate_time(wormholes, mid) < 0) {
            // we didn't make it, speed is too low
            low = mid;
        } else {
            // we did make it, can lower the speed
            high = mid;
        }
    }

    cout << setprecision(15) << fixed <<  high << " " << calculate_time(wormholes, high)
         << endl;
}
