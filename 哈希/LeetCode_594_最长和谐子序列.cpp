#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> temp;
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            temp[nums[i]]++;
            //cout << temp[nums[i]] << endl;
            if (temp.find(nums[i] - 1) != temp.end())
                res = max(res, temp[nums[i]] + temp[nums[i] - 1]);
            if (temp.find(nums[i] + 1) != temp.end())
                res = max(res, temp[nums[i]] + temp[nums[i] + 1]);
        }

        return res;
    }
};