#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = INT16_MAX;
        int result;
        for (int i = 0; i < nums.size(); i++)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {

                if (res > abs(nums[i] + nums[left] + nums[right] - target))
                {
                    result = nums[i] + nums[left] + nums[right];
                    res = abs(nums[i] + nums[left] + nums[right] - target);
                }


                if (nums[i] + nums[left] + nums[right] < target)
                {
                    left++;
                }
                else if(nums[i] + nums[left] + nums[right] > target)
                {
                    right--;
                }
                else
                {
                    return target;
                }
                
                
            }
        }

        return result;

    }
};