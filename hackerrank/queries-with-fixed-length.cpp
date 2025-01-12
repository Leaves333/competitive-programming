#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER_ARRAY queries
 */

vector<int> solve(vector<int> arr, vector<int> queries) {
    vector<int> ans;
    for (auto d : queries) {
        int smol = INT_MAX;
        deque<int> q;

        for (int i = 0; i < d - 1; i++) {
            while (q.size() > 0 && q.back() <= arr[i]) {
                q.pop_back();
            }
            q.push_back(arr[i]);
        }
        
        for (int i = d - 1; i < arr.size(); i++) {
            while (q.size() > 0 && q.back() <= arr[i]) {
                q.pop_back();
            }
            q.push_back(arr[i]);
            smol = min(smol, q.front());
            if (q.size() > 0 && arr[i - d + 1] >= q.front()) {
                q.pop_front();
            }
        }

        ans.push_back(smol);
    }
    return ans;
}
