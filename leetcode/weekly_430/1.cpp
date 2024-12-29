#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int ans = 0;
        for (int col = 0; col < grid[0].size(); col++) {
            for (int row = 1; row < grid.size(); row++) {
                if (grid[row][col] <= grid[row - 1][col]) {
                    ans += grid[row-1][col] - grid[row][col] + 1;
                    grid[row][col] = grid[row-1][col]+1;
                }
            }
        }
        return ans;
    }
};
