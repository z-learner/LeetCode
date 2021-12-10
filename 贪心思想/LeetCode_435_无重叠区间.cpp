#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        if (intervals.empty()) return 0;
        
        sort(intervals.begin(), intervals.end());

        // for (auto nums : intervals)
        // {
        //     for (auto num : nums)
        //     {
        //         cout << num << ",";
        //     }
        //     cout << endl;
        // }

        int cnt = 0;
        vector<int> pre = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < pre[1])
            {
                cnt++;
                if (pre[1] > intervals[i][1])
                {
                    pre = intervals[i];
                }
            }
            else 
            {
                pre = intervals[i];
            }

        }

        return cnt;
    }
};