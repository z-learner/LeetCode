#include <iostream>
#include <vector>

using namespace std;


// dfs 超时
class Solution {
public:
    int res = INT16_MAX;
    int minOperations(vector<int>& nums, int x) {

        int left = 0;
        int right = nums.size() - 1;
        deepIn(nums, left + 1, right, x - nums[left], 1);
        deepIn(nums, left, right - 1, x - nums[right], 1);

        return res == INT16_MAX ? -1 : res;

    }


    void deepIn(vector<int>& nums, int left, int right, int x, int step)
    {

        if (x == 0)
        {
            res = min(res, step);
            return;
        }

        if (x < 0 || left > right) return;

    
        deepIn(nums, left + 1, right, x - nums[left], step + 1);
        deepIn(nums, left, right - 1, x - nums[right], step + 1);

    }
};


// 滑动窗口 找中间最长的片段
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int res = -1;
        int sum = 0;
        for (auto num : nums) sum += num;
        int target = sum - x;
        if (target < 0) return -1;
        int left = 0;
        int windowsSum = 0;
        int right = 0;
        while (right < nums.size())
        {
            windowsSum += nums[right];
            while (windowsSum > target)
            {
                windowsSum -= nums[left];
                left++;
            }

            if (windowsSum == target)
            {
                res = max(res, right - left + 1);
            }

            right++;
        }


        return res == -1 ? -1 : nums.size() - res;


    }
};