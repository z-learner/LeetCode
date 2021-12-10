#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 我们用 dp[i][j] 表示用数组中的前 i 个元素，组成和为 j 的方案数。考虑第 i 个数 nums[i]，它可以被添加 + 或 -，因此状态转移方程如下：
    int findTargetSumWays(vector<int>& nums, int S) {
        // i 代表 元素的个数，而不是下标 index 
        // dp[i][j] = dp[i-1][j - nums[i]] + dp[i-1][j + nums[i]];
        int size = nums.size();
        // j + 1000 为设计的分数
        vector<vector<int>>  dp(size + 1, vector<int>(2001, 0));

        // 这个条件很重要 
        dp[0][1000] = 1;

        for(int i = 1; i <= size; i++){
            int indexI = i - 1;
            for(int score = -1000; score <= 1000; score++ ){
                int one = 0;
                int another = 0;

                if(score - nums[indexI] >= -1000 && score - nums[indexI] <= 1000 ) one = dp[i-1][score - nums[indexI] + 1000];
                if(score + nums[indexI] >= -1000 && score + nums[indexI] <= 1000 ) another = dp[i-1][score + nums[indexI] + 1000];

                dp[i][score + 1000 ] += (one + another);
            }
        }
        return S > 1000 ? 0 : dp.back()[S + 1000];
    }
};

// 作者：hardCoding
// 链接：https://leetcode-cn.com/problems/target-sum/solution/dong-tai-gui-hua-by-hardcoding-13/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。