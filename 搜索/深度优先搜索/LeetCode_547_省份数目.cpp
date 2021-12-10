#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int cnt = 0;
        for (int i = 0; i < isConnected.size(); i++)
        {
            for (int j = 0; j < isConnected.size(); j++)
            {
                if (isConnected[i][j] == 1)
                {
                    cnt++;
                    dfs(isConnected, i, j);
                }
                    
            }
        }

        return cnt;


    }

    void dfs(vector<vector<int>>& isConnected, int x, int y)
    {
        isConnected[x][y] = 0;
        isConnected[y][x] = 0;

        for (int i = 0; i < isConnected.size(); i++)
        {
            if (isConnected[y][i] == 1)
                dfs(isConnected, y, i);
        }

        return ;
    }
};