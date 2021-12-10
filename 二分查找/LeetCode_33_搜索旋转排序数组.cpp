#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[0]) //前半部分
            {
                if (nums[0] <= target && target < nums[mid]) //target如果存在 一在在0 ， mid 之间
                    right = mid - 1;
                else  
                    left = mid + 1;
            }
            else  //后半部分   
            {
                if (target <= nums[right] && nums[mid] < target) //一定位于 mid - right 之间
                    left = mid + 1;
                else   
                    right = mid - 1;
            }
        }

        return -1;


    }
};