#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
		string word = "a";
		while (word.length() < k) {
			string new_word = "";
			for (char c : word) {
				new_word += c + 1;
			}
			word += new_word;
		}
		return word[k - 1];
    }
};
