#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        int p = 0;
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (res.back()[1] >= intervals[i][1])
            {
                continue;
            }
            else if(res.back()[1] >= intervals[i][0])
            {
                res.back()[1] = intervals[i][1];
            }
            else 
            {
                res.push_back(intervals[i]);
            }

        }

        return res;

    }
};