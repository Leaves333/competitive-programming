#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        int size = word.length() - numFriends + 1;
        string largest = word.substr(0, size);
        for (int i = 1; i < word.length() - size + 1; i++) {
            string cur = word.substr(i, size);
            largest = max(cur, largest);
        }
        if (numFriends != 1) {
            for (int i = word.length() - size + 1; i < word.length(); i++) {
                string cur = word.substr(i);
                largest = max(cur, largest);
            }
        }
        return largest;
    }
};
