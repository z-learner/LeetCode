#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0)); // 0 : 枪当前的房屋  1 : 不强当前的房屋
        //int(*dp)[2] = new int[n][2];
        dp[0][0] = nums[0];
        dp[0][1] = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            dp[i][0] = nums[i] + dp[i - 1][1];
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        } 

        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        //vector<vector<int>> dp(nums.size(), vector<int>(2, 0)); // 0 : 枪当前的房屋  1 : 不强当前的房屋
        //int(*dp)[2] = new int[n][2];
        int *dp = new int[nums.size()];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[nums.size() - 1];
    }
};

