#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOfSubstrings(string word, int k) {

		int ans = 0;
		for (int i = 0; i < word.length(); i++) {
			
			/*unordered_map<char, int> vowels = {{'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};*/
			int arr[256];
			memset(arr, 0, sizeof(arr));

			int consonants = 0;
			bool flag = false;
			for (int j = i; j < word.length(); j++) {
				char c = word[j];
				if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
					arr[c]++;
				} else {
					consonants++;
				}
				
				if (!flag && arr['a'] > 0 && arr['e'] > 0 && arr['i'] > 0 && arr['o'] > 0 && arr['u'] > 0) {
					flag = true;
				}
				if (consonants > k) {
					break;
				}
				ans += flag && consonants == k;

				/*cout << i << " " << j << " " << flag << endl;*/
				/*cout << "consonants: " << consonants << endl;*/
				/*cout << "ans: " << ans << endl;*/
				/*for (auto x : vowels) {*/
				/*	cout << x.first << ": " << x.second << endl;*/
				/*}*/
				/*cout << endl;*/
			}

		}

		return ans;
    }
};
