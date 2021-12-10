#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = N > 0 ? grid[0].size() : 0;
        vector<vector<int>> dp = grid;
        //dp[0][0] = grid[0][0];
        //第一行
        for (int i = 1; i < M; i++)
        {
            dp[0][i] += dp[0][i - 1];
        }
        //第一列
        for (int i = 1; i < N; i++)
        {
            dp[i][0] += dp[i - 1][0];
        }
        //里面的内容
        for (int i = 1; i < N; i++)
        {
            for (int j = 1; j < M; j++)
            {
                dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]); 
            }
        }

        return dp[N - 1][M - 1];
        
    }
};