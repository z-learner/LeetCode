#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;




/* heap use after free ???????????? */
class Solution {
public:
    
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) return {};
        set<int> map;
        for (int num : nums)
            map.insert(num);
        vector<vector<int>> res;
        vector<int> temp;

        permute(res, temp, map, 0, nums.size());
        return res;

    }

    void permute(vector<vector<int>>& res, vector<int> temp, set<int>& map, int index, int size)
    {
        
        if (index == size)
        {
            cout << "开始插入" << endl;
            res.emplace_back(temp);
            cout << "插入结束"  << endl;
            return ;
        }
            
        
        for (auto m : map)
        {
            map.erase(m);
            temp.push_back(m);

            cout << "递归深度 ： " << index + 1 << "----";
            for (auto t : temp)
                cout << t;
            cout << endl;
            permute(res, temp, map, index + 1, size);
            cout << "开始回溯 : " << m << endl;
            temp.pop_back();
            map.insert(m);
            cout << "结束一层回溯 : " << m << endl;

        }

        return;
    }
};






/* 参考 */
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking (vector<int>& nums, vector<bool>& used) {
        // 此时说明找到了一组
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) continue; // path里已经收录的元素，直接跳过
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};

