#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();   

        vector<vector<bool> > memo(m, vector<bool>(n, true));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0 && memo[i][j])
                {
                    // 行
                    for (int k = 0; k < n; k++)
                    {
                        if (matrix[i][k] != 0)
                        {
                            matrix[i][k] = 0;
                            memo[i][k] = false;
                        }
                    }

                    // 列
                    for (int k = 0; k < m; k++)
                    {
                        if (matrix[k][j] != 0)
                        {
                            matrix[k][j] = 0;
                            memo[k][j] = false;
                        }
                    }
                }
            }
        }


    }
};