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

    
    ll limit = 1e18;
    const int N = 100000;
    vb sieve(N, true);
    vi primes;
    for (int i = 2; i < N; i++) {
        if (!sieve[i])
            continue;
        primes.push_back(i);
        for (int j = i; j < N; j += i) {
            sieve[j] = false;
        }
    }

    ll cur = 1;
    for (int i = 0; i < primes.size(); i++) {
        ll next = cur * primes[i];
        if (next > limit || next < cur) {
            cout << primes[i] << endl;
            break;
        }
        cur = next;
    }
}
