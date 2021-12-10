#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        //三维数组
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1,0)));
        for (int i = 1; i <= strs.size(); i++)
        {
            auto temp = getSumOfStr(strs[i - 1]);
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j - temp.first >= 0 && k - temp.second >= 0)
                        dp[i][j][k] = max(
                            dp[i - 1][j - temp.first][k - temp.second] + 1,
                            dp[i][j][k]
                            );
                }
            }
        }

        return dp[strs.size()][m][n];
    }

    pair<int, int> getSumOfStr(string s)
    {
        int s1 = 0;
        int s2 = 0;
        for (auto ch : s)
        {
            if (ch == '0') s1++;
            if (ch == '1') s2++;
        }

        return make_pair(s1, s2);
    }
};