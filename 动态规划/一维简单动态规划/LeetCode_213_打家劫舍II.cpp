#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        //bool selectFirst = false;
        //bool selectEnd = false;

        const int N = nums.size();
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        //if (nums.size() == 2) return nums[1];
        vector<int> dp1(N, 0); //不偷第一个
        dp1[0] = 0;
        dp1[1] = nums[1];
        for (int i = 2; i < N; i++)
        {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
        }

        vector<int> dp2(N, 0); //不偷最后一个
        dp2[0] = nums[0];
        dp2[1] = max(nums[0], nums[1]);
        for (int i = 2; i < N; i++)
        {
            if (i == N - 1) dp2[i] = dp2[i - 1]; 
            else  dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
        }

        return max(dp1[N - 1], dp2[N - 1]);
        
    }
};