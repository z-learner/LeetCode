#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return vector<int>{-1,-1};
        int left = 0;
        int right = nums.size() - 1;
        vector<int> res;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
            
        }

        if (nums[left] != target )
        {
            return vector<int>{-1,-1};
        }
        res.push_back(left);
        right = nums.size() - 1;
        /*
        while (left < right)
        {
            int mid = (left + right) >> 1;
            if (nums[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
            
        }

        res.push_back(nums[left] == target ? left : left - 1);
        */

        while (left < right)
        {
            int mid = (left + right + 1) >> 1;
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid;
            }
            
        }
        
        res.push_back(left);

        return res;
    }
};