#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> stringSequence(string target) {

		vector<string> ans;
		string cur = "a";
		ans.push_back("a");

		while (cur != target) {
			if (cur[cur.length() - 1] != target[cur.length() - 1]) {
				cur[cur.length() - 1]++;
			} else {
				cur += "a";
			}
			ans.push_back(cur);
		}

		return ans;

    }
};
