#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> temp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            /* code */
            if (temp.find(nums[i]) != temp.end())
            {
                /* code */
                return true;
            }
            temp.insert(nums[i]);
            
        }

        return false;
        
    }
};