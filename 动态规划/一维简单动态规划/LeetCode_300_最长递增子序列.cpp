#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();

        vector<int> dp(size, 1);

        int Max = 1;

        for (int i = 1; i < size; i++)
        {
            int pre = i - 1;
            while (pre >= 0)
            {
                if (nums[pre] < nums[i])
                {
                    dp[i] = max(dp[i], dp[pre] + 1);
                }
                pre--;
            }

            Max = max(Max, dp[i]);
        }

        return Max;

        
    }
};



class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        vector<int> dp(size, 0);
        dp[0] = nums[0];
        int len = 0;

        for (int i = 1; i < size; i++)
        {
            
            if (nums[i] > dp[len])
                dp[++len] = nums[i];
            else    //寻找第一个 比 num[i] 小的数值
            {
                int left = 0;
                int right = len;
                while (left < right)
                {
                    int mid = (left + right ) / 2 + 1;
                    if (dp[mid] >= nums[i])
                        right = mid - 1;
                    else  
                        left = mid;
                }

                if (dp[left] < nums[i])
                    dp[left + 1] = nums[i];
                else  
                    dp[left] = nums[i];

            }
            //
        }

        return len + 1;

        
    }
};