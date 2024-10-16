#include <bits/stdc++.h>
using namespace std;

int main() {

	// generate squares of primes
	unordered_set<long long> squares;
	bool prime[1000001];
	memset(prime, true, sizeof(prime));
	
	for (long long i = 2; i <= 1000000; i++) {
		if (prime[i]) {
			squares.insert(i * i);
			for (int k = i; k < 1000001; k += i) {
				prime[k] = false;
			}
		}
	}

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		if (squares.count(x) > 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
