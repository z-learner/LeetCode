#include <iostream>
#include <vector>

using namespace std;
//子数组 （理解错题意）
// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         if (nums.size() <= 1) return nums.size();
//         int size = nums.size();
//         //构造差值数列
//         vector<int> subArray;
//         for (int i = 1; i < size; i++)
//         {
//             subArray.push_back(nums[i] - nums[i - 1]);
//         }
//         vector<int> dp(subArray.size(), 1);
//         if (subArray[0] != 0)  dp[0] = 2;
//         int Max = max(1, dp[0]);
//         for (int i = 1; i < subArray.size(); ++i)
//         {
//             if (subArray[i] == 0)
//                 continue;
//             else if (subArray[i] * subArray[i - 1] == 0)
//                 dp[i] = 2;
//             else if (subArray[i] * subArray[i - 1] < 0)
//                 dp[i] = dp[i - 1] + 1;
//             else if (subArray[i] * subArray[i - 1] > 0)
//                 dp[i] = 2;

//             Max = max(dp[i], Max);
//         }
        
        
//         return Max;
//     }
// };





class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }
        vector<int> up(n), down(n);
        up[0] = down[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up[i] = max(up[i - 1], down[i - 1] + 1);
                down[i] = down[i - 1];
            } else if (nums[i] < nums[i - 1]) {
                up[i] = up[i - 1];
                down[i] = max(up[i - 1] + 1, down[i - 1]);
            } else {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }
        return max(up[n - 1], down[n - 1]);
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/wiggle-subsequence/solution/bai-dong-xu-lie-by-leetcode-solution-yh2m/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。