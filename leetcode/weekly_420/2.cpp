#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s, int k) {

		const string kChars = "qwertyuiopasdfghjklzxcvbnm";
		int ans = 0;

		for (int i = 0; i < s.length(); i++) {
			unordered_map<char, int> freq;
			for (char c : kChars) {
				freq[c] = 0;
			}
			bool flag = false;
			for (int j = i; j < s.length(); j++) {
				freq[s[j]]++;
				if (flag || freq[s[j]] >= k) {
					flag = true;
					ans++;
				}
			}
		}
		return ans;
    }
};
