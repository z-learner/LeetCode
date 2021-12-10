#include <iostream>
#include <vector>

using namespace std;


// 超时
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