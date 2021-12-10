#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            int temp = - nums[i];
            while (left < right)
            {

                if (right < nums.size() - 1 && nums[right] == nums[right + 1])
                {
                    right--;
                    continue;
                }

                if (nums[left] + nums[right] == temp)
                {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }
                else if (nums[left] + nums[right] < temp)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return res;


    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            //memo.insert(nums[i]);
            int target = -nums[i];
            unordered_set<int> memo;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2]) continue;
                if (memo.find(target - nums[j]) != memo.end())
                {
                    res.push_back({nums[i], nums[j], target - nums[j]});
                    memo.erase(target - nums[j]);
                }
                else
                    memo.insert(nums[j]);
            }
            //memo.clear();
        }

        return res;
    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            int temp = -nums[i];
            while (left < right)
            {
                if (nums[left] + nums[right] == temp)
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    do left++; while(nums[left] == nums[left - 1] && left < right);
                    do right--; while(nums[right] == nums[right + 1] && left < right);
                }
                else if(nums[left] + nums[right] > temp)
                {
                    //do left++; while(nums[left] == nums[left - 1] && left < right);
                    do right--; while(nums[right] == nums[right + 1] && left < right);
                }
                else   
                {
                    do left++; while(nums[left] == nums[left - 1] && left < right);
                    //do right--; while(nums[right] == nums[right + 1] && left < right);
                }
            }
        }

        return res;
    }
};