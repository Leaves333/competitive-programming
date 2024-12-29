#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfSubsequences(vector<int> &nums) {
        long long ans = 0;
        for (int p = 0; p < nums.size() - 2; p++) {

            map<int, int> between;
            map<int, int> from_end;

            // init values
            between[nums[p + 2]]++;
            for (int i = p + 6; i < nums.size(); i++) {
                from_end[nums[i]]++;
            }

            for (int r = p + 4; r < nums.size() - 2; r++) {

                long long starting = ans;

                // find factors
                int product = nums[p] * nums[r];
                /*cout << "product " << product << endl;*/
                /*set<int> factors_used;*/
                for (int i = 1; i <= sqrt(product); i++) {
                    /*cout << "testing... " << i << endl;*/
                    if (product % i != 0)
                        continue;
                    /*if (factors_used.count(i) || factors_used.count(product / i))*/
                    /*    continue;*/
                    /*cout << "is a factor " << i << endl;*/
                    /*factors_used.insert(i);*/
                    /*factors_used.insert(product / i);*/
                    ans += between[i] * from_end[product / i];
                    if (i != product / i)
                        ans += between[product / i] * from_end[i];
                }

                /*cout << p << " " << r << " " << ans - starting << endl;*/
                between[nums[r - 1]]++;
                from_end[nums[r + 2]]--;
            }
        }
        return ans;
    }
};
