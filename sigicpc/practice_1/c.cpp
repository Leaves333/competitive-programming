#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int testcases; cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		long long n, k;
		cin >> n >> k;

		long long biggest_value = 0;
		long long total_cards = 0;
		for (long long i = 0; i < n; i++) {
			long long x;
			cin >> x;
			if (x > biggest_value) {
				biggest_value = x;
			}
			total_cards += x;
		}

		/*cout << "total cards = " << total_cards << endl;*/
		/*cout << "highest value = " << biggest_value << endl;*/

		long long ans = 0;
		for (long long i = 1; i <= n; i++) {
			long long remainder = total_cards % i;
			/*cout << "testing if divisble by " << i << endl;*/
			if (i - remainder <= k || remainder == 0) {
				long long number_of_decks = (total_cards + k) / i;
				/*cout << "is divisible by " << i << ", number of decks = " << number_of_decks << endl;*/
				if (number_of_decks >= biggest_value) {
					ans = i;
					/*cout << "updated ans" << endl;*/
				}
			}
		}
		
		cout << ans << endl;

	}

}
