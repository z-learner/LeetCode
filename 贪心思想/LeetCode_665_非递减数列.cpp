#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {

        int cnt = 0;
        //邻近两数不满足要求 先改变靠前的那个(令 nums[i - 1] = nums[i]), 这样不会影响后面的进度
        // 但也有一种情况 例外 即 nums[i - 2] > nums[ i ] ， 这样的话 改变 i - 1处 的位置的 数 就不符合要求了
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] > nums[i] && i > 1 && nums[i - 2] > nums[i])
            {
                nums[i] = nums[i - 1];
                cnt++;
            }
            else if (nums[i - 1] > nums[i])
            {
                nums[i - 1] = nums[i];
                cnt++;
            }
        }

        return cnt <= 1;
    }
};