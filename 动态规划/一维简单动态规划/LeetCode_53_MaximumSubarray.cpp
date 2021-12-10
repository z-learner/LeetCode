#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        int res = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }

        return res;

    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return -1;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int maxRes = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(
                dp[i - 1] + nums[i],
                nums[i]
            );
            maxRes = max(maxRes, dp[i]);
        }

        return maxRes;
    }
};