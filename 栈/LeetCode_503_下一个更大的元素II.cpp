#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<pair<int, int>> temp;
        vector<int> res(nums.size(), -1);
        for (int i = 0; i < nums.size(); i++)
        {
            while (!temp.empty() && nums[i] > temp.top().first)
            {
                res[temp.top().second] = nums[i];
                temp.pop();
            }
            temp.push(make_pair(nums[i], i));
        }

        for (int i = 0; i < nums.size() && !temp.empty() && i < temp.top().second; i++)
        {
            while (nums[i] > temp.top().first)
            {
                res[temp.top().second] = nums[i];
                temp.pop();
            }
        }

        return res;

    }
};