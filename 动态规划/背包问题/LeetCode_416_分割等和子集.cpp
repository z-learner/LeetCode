#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() <= 1) return false;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }        

        if (sum % 2 == 1) return false;
        sum = sum / 2;
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= nums.size(); ++i) dp[i][0] = true; //什么都不选 

        for (int i = 1; i <= nums.size(); i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                //如果不选 i 
                dp[i][j] = dp[i - 1][j]; //
                if (j - nums[i - 1] >= 0)
                {
                    dp[i][j] = dp[i][j] | dp[i-1][j-nums[i-1]];
                }
            }
        } 

        return dp[nums.size()][sum];

    }
};