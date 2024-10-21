#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	unordered_map<int, vector<int>> edges;

	bool is_palindrome(string& s) {
		int left = 0, right = s.length() - 1;
		while (left < right) {
			if (s[left] != s[right]) {
				return false;
			}
			left++;
			right--;
		}
		return true;
	}

	string dfs(int x, const string& s, vector<bool>& ans) {
		string res = "";
		for (int dest : edges[x]) {
			res += dfs(dest, s, ans);
		}

		res += s[x];
		ans[x] = is_palindrome(res);
		return res;
	}

    vector<bool> findAnswer(vector<int>& parent, string s) {
		for (int i = 1; i < parent.size(); i++) {
			edges[parent[i]].push_back(i);
		}

		vector<bool> ans(parent.size());
		dfs(0, s, ans);
		return ans;
    }
};
