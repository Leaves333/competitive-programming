#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
		long long bit = 1;
		int shift = 0;
		for (int i = 0; i < min(48, (int) operations.size()); i++) {
			if (operations[i] == 1 && (k - 1) & bit << i) {
				shift++;
			}
		}
		return 'a' + (shift % 26);
    }
};
