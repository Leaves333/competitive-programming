#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOfSubstrings(string word, int k) {

		int ans = 0;
		for (int i = 0; i < word.length(); i++) {
			
			map<char, int> vowels = {{'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};
			int consonants = 0;
			for (int j = i; j < word.length(); j++) {
				char c = word[j];
				if (vowels.count(c) > 0) {
					vowels[c]++;
				} else {
					consonants++;
				}
				
				if (vowels['a'] > 0 && vowels['e'] > 0 && vowels['i'] > 0 && vowels['o'] > 0 && vowels['u'] > 0) {
					if (consonants == k) {
						ans++;
					}
				}
			}

			/*cout << i << " " << j << endl;*/
			/*cout << "consonants: " << consonants << endl;*/
			/*cout << "ans: " << ans << endl;*/
			/*for (auto x : vowels) {*/
			/*	cout << x.first << ": " << x.second << endl;*/
			/*}*/
			/*cout << endl;*/

		}

		return ans;
    }
};
