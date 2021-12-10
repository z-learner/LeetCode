#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        //res.push_back(temp);
        dfs(nums,res,-1,temp);
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, int index, vector<int> temp)
    {
        res.push_back(temp);
        for (int i = index + 1; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            dfs(nums, res, i, temp);
            temp.pop_back();
        }

        return;
    }
};




class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        res.push_back(temp);
        dfs(nums,res,-1,temp);
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, int index, vector<int> temp)
    {
        if(index == nums.size())
        {
            return;
        }
        

        for (int i = index + 1; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            res.push_back(temp);
            dfs(nums, res, i, temp);
            temp.pop_back();
        }

        return;
    }
};