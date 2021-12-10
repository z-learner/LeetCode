#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            bool flag = nums[mid] == nums[mid + 1]; 
            if(flag) //判读左右区间 那个是有双数个数
            {
                if ((mid - left) % 2 == 0)
                {
                    left = mid + 2;
                }
                else
                {
                    right = mid - 1;
                }
            }
            else
            {
                if ((right - mid) % 2 == 0)
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }

        return nums[left];
    }
};