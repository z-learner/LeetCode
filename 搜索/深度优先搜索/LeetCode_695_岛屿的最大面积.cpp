#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                    res = max(res, maxAreaOfIsland(grid, i, j));
            }
        }

        return res;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid, int x, int y)
    {
        int ans = 1;
        grid[x][y] = 0;
        vector<int> dis{-1, 0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int newx = x + dis[i];
            int newy = y + dis[i + 1];
            if (newx >= 0 && newx < grid.size() && newy >= 0 && newy < grid[0].size() && (grid[newx][newy] == 1))
            {
                ans += maxAreaOfIsland(grid, newx, newy);
            }
        }

        return ans;
        
    }
};