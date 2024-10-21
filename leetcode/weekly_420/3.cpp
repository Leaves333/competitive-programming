#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {

		int operations = 0;
		for (int i = nums.size() - 2; i >= 0; i--) {
			if (nums[i] > nums[i + 1]) {
				for (int k = 2; k < ceil(sqrt(nums[i])) + 1; k++) {
					if (nums[i] % k == 0) {
						nums[i] = k;
						operations++;
						break;
					}
				}

				// check if division actually fixes the array
				if (nums[i] > nums[i + 1]) {
					return -1;
				}
			}
		}

		return operations;

    }
};
