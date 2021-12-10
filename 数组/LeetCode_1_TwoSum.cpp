#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> temp;
        for(int i = 0; i < nums.size(); i++)
        {
            int res = target - nums[i];
            if (temp.find(res) != temp.end())
            {
                return vector<int>{temp[res], i};
            }
            else
            {
                temp.insert({nums[i], i});
            }
            
        }

        return vector<int>{0,0};



    }
};