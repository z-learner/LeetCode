#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        dfs(candidates,target,0,temp, -1);
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

        for (int i = index + 1; i < candidates.size(); i++)
        {
            //candidates 已排序
            if (i > index + 1 && candidates[i] == candidates[i-1]) continue;   //important step 平级的情况下 不可以有重复值
            if (tempSum + candidates[i] > target) break;
            temp.push_back(candidates[i]);
            tempSum += candidates[i];
            dfs(candidates,target,tempSum,temp,i);
            temp.pop_back();
            tempSum -= candidates[i];
        }

        return;
    }
};

