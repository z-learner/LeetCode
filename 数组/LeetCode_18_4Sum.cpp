#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            for (int j = i + 1; j < nums.size(); j++)
            {
                if ( j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    if (nums[i] + nums[j] + nums[left] + nums[right] == target)
                    {
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while (nums[left] == nums[left - 1] && left < right)
                        {
                            left++;
                        }
                    }
                    else if(nums[i] + nums[j] + nums[left] + nums[right] > target)
                    {
                        right--;
                    }
                    else
                    {
                        left++;
                    }
                    
                }
            }
        }

        return res;

    }
};