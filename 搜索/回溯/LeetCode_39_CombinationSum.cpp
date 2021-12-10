#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> temp;
        dfs(candidates,target,0,temp, 0);
        return res;

    }

    void dfs(vector<int>& candidates, int target, int tempSum, vector<int>& temp, int index)
    {
        if (tempSum == target)
        {
            res.push_back(temp);
            return;
        }

        if (tempSum > target)
        {
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            temp.push_back(candidates[i]);
            tempSum += candidates[i];
            dfs(candidates,target,tempSum,temp,i);
            temp.pop_back();
            tempSum -= candidates[i];
        }

        return;
    }
};


class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        dfs(candidates,target,0,temp, 0);
        return res;

    }

    bool dfs(vector<int>& candidates, int target, int tempSum, vector<int>& temp, int index)
    {
        if (tempSum == target)
        {
            res.push_back(temp);
            return false;
        }

        if (tempSum > target)
        {
            return true;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            temp.push_back(candidates[i]);
            tempSum += candidates[i];
            bool btemp = dfs(candidates,target,tempSum,temp,i);
            temp.pop_back();
            tempSum -= candidates[i];
            if (btemp == true) break;
        }

        return false;
    }
};