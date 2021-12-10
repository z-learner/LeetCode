#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        vector<int> dp(n + 1, -1);
        vector<int> squaresNum;
        for (int i = 1; i * i <= n; i++)
        {
            squaresNum.push_back(i * i);
        }
        dp[0] = 0;
        dp[1] = 1;//base case
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            //遍历 平方数
            int curMin = i;
            //bool flag = false;
            for (int j = 0; j < squaresNum.size() && squaresNum[j] <= i; j++)
            {
                // if (dp[i - squaresNum[j]] == -1)
                //     continue;
                curMin = min(
                    curMin,
                    1 + dp[i - squaresNum[j]]
                );
                //flag = true;
            }
            dp[i] = curMin;
        }

        return dp[n];

    }
};