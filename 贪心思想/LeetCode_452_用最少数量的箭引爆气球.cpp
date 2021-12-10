#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        sort(points.begin(), points.end());

        // for (auto nums : points)
        // {
        //     for (auto num : nums)
        //     {
        //         cout << num << ",";
        //     }
        //     cout << endl;
        // }

        int cnt = 0;
        vector<int> pre = points[0];
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] <= pre[1])
            {
                cnt++;
                if (pre[1] > points[i][1])
                {
                    pre = points[i];
                }
            }
            else 
            {
                pre = points[i];
            }

        }

        return points.size() - cnt;
    }
};